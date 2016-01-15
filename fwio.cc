#include "fwiocl.h"

#ifdef SOCKET_AVAIL
# include HEADER_SOCKET
#endif

#include <windows.h>
#include <io.h>
#include <fcntl.h>


cl_io::cl_io(): cl_f()
{
  last_used= first_free= 0;
}

cl_io::cl_io(chars fn, chars mode): cl_f(fn, mode)
{
  last_used= first_free= 0;
}

cl_io::cl_io(int the_server_port): cl_f(the_server_port)
{
  last_used= first_free= 0;
}

int
cl_io::put(char c)
{
  int n= (first_free + 1) % 1024;
  if (n == last_used)
    return -1;
  buffer[first_free]= c;
  first_free= n;
  return 0;
}

int
cl_io::get(void)
{
  if (last_used == first_free)
    return -1;
  char c= buffer[last_used];
  last_used= (last_used + 1) % 1024;
  return c;
}

enum file_type
cl_io::determine_type()
{
  DWORD _file_type = GetFileType(handle);

  switch (_file_type)
    {
    case FILE_TYPE_CHAR:
      {
        DWORD err;
	if (file_id > 2)
	  return F_FILE;
        if (!ClearCommError(handle, &err, NULL))
          {
            switch (GetLastError())
              {
              case ERROR_INVALID_HANDLE:
		printf("wio file_id=%d (handle=%p) type=console\n", file_id, handle);
                return F_CONSOLE;
		
              case ERROR_INVALID_FUNCTION:
                /*
                 * In case of NUL device return type F_FILE.
                 * Is this the correct way to test it?
                 */
		printf("wio file_id=%d (handle=%p) type=file\n", file_id, handle);
                return F_FILE;

              default:
                //assert(false);
		printf("wio file_id=%d (handle=%p) type=unknown\n", file_id, handle);
		return F_UNKNOWN;
              }
          }
      }
      printf("wio file_id=%d (handle=%p) type=serial\n", file_id, handle);
      return F_SERIAL;

    case FILE_TYPE_DISK:
      printf("wio file_id=%d (handle=%p) type=file2\n", file_id, handle);
      return F_FILE;
    }

  char sockbuf[256];
  int optlen = sizeof(sockbuf);

  if (SOCKET_ERROR != getsockopt((SOCKET)handle, SOL_SOCKET, SO_TYPE, sockbuf, &optlen) ||
      WSAENOTSOCK != WSAGetLastError())
    {
      printf("wio file_id=%d (handle=%p) type=socket\n", file_id, handle);
      return F_SOCKET;
    }
  
  //assert(false);
  printf("wio file_id=%d (handle=%p) type=unknown2\n", file_id, handle);
  return F_UNKNOWN;
}

int
cl_io::read(char *buf, int max)
{
  if (type != F_CONSOLE)
    return cl_f::read(buf, max);
  int i= 0, c= get();
  //printf("CONSOLE read(%d) last_used=%d first_free=%d\n", max, last_used, first_free);
  while (c >= 0)
    {
      if (i >= max)
	return i;
      buf[i]= c;
      i++;
      c= get();
    }
  return (i==0)?-1:i;
}

int
cl_io::input_avail(void)
{
  //e_handle_type type= F_UNKNOWN;
  //if (F_UNKNOWN == type)
  //type = get_handle_type();

  switch (type)
    {
    case F_SOCKET:
      {
        struct timeval tv = {0, 0};
	
        //assert(INVALID_HANDLE_VALUE != handle);
	
        fd_set s;
        FD_ZERO(&s);
        FD_SET((SOCKET)handle, &s);

        int ret = select(0, &s, NULL, NULL, &tv);
        if (SOCKET_ERROR == ret)
          fprintf(stderr, "Can't select: %d\n", WSAGetLastError());

        return ret != SOCKET_ERROR && ret != 0;
      }

    case F_FILE:
      return true;

    case F_CONSOLE:
      {
        PINPUT_RECORD pIRBuf;
        DWORD NumPending;
        DWORD NumPeeked;
	bool ret= last_used != first_free;
        /*
         * Peek all pending console events
         */
	//printf("win iput check on console id=%d handle=%p\n", file_id, handle);
        if (INVALID_HANDLE_VALUE == handle)
	  {
	    //printf("01\n");
	    return ret;
	  }
	if (!GetNumberOfConsoleInputEvents(handle, &NumPending))
	  {
	    //printf("02\n");
	    return ret;
	  }
	if (NumPending == 0)
	  {
	    //printf("03\n");
	    return ret;
	  }
	if (NULL == (pIRBuf = (PINPUT_RECORD)_alloca(NumPending * sizeof(INPUT_RECORD))))
	  {
	    //printf("04\n");
	    return ret;
	  }
	
        if (ReadConsoleInput(handle, pIRBuf, NumPending, &NumPeeked) == 0)
	  {
	    //printf("1\n");
	    free(pIRBuf);
	    return ret;
	  }
	if (NumPeeked == 0L)
	  {
	    //printf("2\n");
	    free(pIRBuf);
	    return ret;
	  }
	if (NumPeeked > NumPending)
	  {
	    //printf("3\n");
	    free(pIRBuf);
	    return ret;
	  }
	/*
	 * Scan all of the peeked events to determine if any is a key event
	 * which should be recognized.
	 */
	//printf("3 pending=%ld peeked=%ld\n", NumPending, NumPeeked);
	int key_presses= 0;
	for ( ; NumPeeked > 0 ; NumPeeked--, pIRBuf++ )
	  {
	    if (KEY_EVENT == pIRBuf->EventType &&
		pIRBuf->Event.KeyEvent.bKeyDown)
	      {
		char c= pIRBuf->Event.KeyEvent.uChar.AsciiChar;
		key_presses++;
		if ((c == '\n') ||
		    (c == '\r'))
		  {
		    //printf("CR/LF pending=%ld peeked=%ld\n", NumPending, NumPeeked);
		  }
		//printf("presses=%d found (c=%d/%c)\n", key_presses, c, (c>31)?c:'.');
		/*free(pIRBuf);
		  return true;*/
		put(c);
		printf("%c",c);
		fflush(stdout);
	      }
	  }
      
	//printf("4 pending=%ld presses=%d\n", NumPending, key_presses);
	//printf("last_used=%d first_free=%d\n", last_used, first_free);
	free(pIRBuf);
        return last_used != first_free;
      }
      
    case F_SERIAL:
      {
        DWORD err;
        COMSTAT comStat;
	
        bool res = ClearCommError(handle, &err, &comStat);
        //assert(res);
	
        return res ? comStat.cbInQue > 0 : false;
      }
      
    default:
      //assert(false);
      return false;
    }
}

void
cl_io::changed(void)
{
  //printf("win_f changed\n");
  if (file_id < 0)
    {
      // CLOSE
      if (F_SOCKET == type)
	{
	  shutdown((SOCKET)handle, SD_BOTH);
	  closesocket((SOCKET)handle);
	}
      handle= INVALID_HANDLE_VALUE;
      type= F_UNKNOWN;
      return;
    }

  // OPEN
  if (server_port > 0)
    {
      //printf("win opened socket id=%d\n", file_id);
      handle= (void*)file_id;
      type= F_SOCKET;
    }
  else
    {
      handle= (HANDLE)_get_osfhandle(file_id);
      type= determine_type();
      if (type == F_CONSOLE)
	{
	  if (strcmp("r", file_mode) == 0)
	    SetConsoleMode(handle, 0);
	}
    }
  //printf("win opened file id=%d\n", file_id);
  //printf("win handle=%p type=%d\n", handle, type);
}


static void
init_winsock(void)
{
  static bool is_initialized = false;

  if (!is_initialized)
    {
      WSADATA wsaData;

      // Initialize Winsock
      int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
      if (iResult != 0)
        {
          //printf("WSAStartup failed: %d\n", iResult);
          exit(1);
        }
    }
}


int
make_server_socket(int port)
{
  init_winsock();

  struct sockaddr_in name;

  //printf("make_server_socket(%d)\n", port);
  /* Create the socket. */
  /*SOCKET*/unsigned int sock = WSASocket(PF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
  if (INVALID_SOCKET == sock)
    {
      fprintf(stderr, "socket: %d\n", WSAGetLastError());
      return INVALID_SOCKET;
    }

  name.sin_family     = AF_INET;
  name.sin_port       = htons(port);
  name.sin_addr.s_addr= htonl(INADDR_ANY);
  if (SOCKET_ERROR == bind(sock, (struct sockaddr *)&name, sizeof(name)))
    {
      fprintf(stderr, "bind: %d\n", WSAGetLastError());
      return INVALID_SOCKET;
    }

  //printf("socket=%d\n", sock);
  return sock;
}


class cl_f *
mk_io(chars fn, chars mode)
{
  class cl_io *io;

  io= new cl_io(fn, mode);
  io->init();
  return io;
}

class cl_f *
cp_io(FILE *f, chars mode)
{
  class cl_io *io;

  io= new cl_io();
  if (f)
    io->use_opened(fileno(f), mode);
  return io;
}

class cl_f *
mk_srv(int server_port)
{
  class cl_io *io;

  //printf("mk_srv(%d)\n", server_port);
  io= new cl_io(server_port);
  io->init();
  return io;
}

int
srv_accept(int server_port, int new_sock,
	   class cl_f **fin, class cl_f **fout)
{
  class cl_io *io;
  //printf("win srv_accept(port=%d,sock=%d)\n", server_port, new_sock);
  int fh= _open_osfhandle((intptr_t)new_sock, _O_TEXT);
  //printf("Accept, got fh=%d for new_socket %p\n", fh, (void*)new_sock);
  if (fin)
    {
      io= new cl_io();
      if (new_sock > 0)
	{
	  if (fh > 0)
	    {
	      FILE *f= fdopen(fh, "r");
	      //printf("fdopened f=%p for fh=%d as input\n", f, fh);
	      io->own_opened(f, cchars("r"));
	      io->type= F_SOCKET;
	      io->server_port= server_port;
	    }
	}
      *fin= io;
    }

  if (fout)
    {
      io= new cl_io();
      if (new_sock > 0)
	{
	  //int fh= _open_osfhandle((intptr_t)new_sock, _O_TEXT);
	  if (fh > 0)
	    {
	      FILE *f= fdopen(fh, "w");
	      //printf("fdopened f=%p for fh=%d as output\n", f, fh);
	      io->use_opened(f, cchars("w"));
	      io->type= F_SOCKET;
	      io->server_port= server_port;
	    }
	}
      *fout= io;
    }

  return 0;
}

void
msleep(int msec)
{
  Sleep(msec);
}


/* End of fwio.cc */
