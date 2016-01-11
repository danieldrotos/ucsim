#include "fwiocl.h"

#ifdef SOCKET_AVAIL
# include HEADER_SOCKET
#endif

#include <windows.h>
#include <io.h>
#include <fcntl.h>


enum e_handle_type
cl_io::get_handle_type()
{
  DWORD file_type = GetFileType(handle);

  switch (file_type)
    {
    case FILE_TYPE_CHAR:
      {
        DWORD err;
	
        if (!ClearCommError(handle, &err, NULL))
          {
            switch (GetLastError())
              {
              case ERROR_INVALID_HANDLE:
                return CH_CONSOLE;
		
              case ERROR_INVALID_FUNCTION:
                /*
                 * In case of NUL device return type CH_FILE.
                 * Is this the correct way to test it?
                 */
                return CH_FILE;

              default:
                //assert(false);
		return CH_UNDEF;
              }
          }
      }
      return CH_SERIAL;

    case FILE_TYPE_DISK:
      return CH_FILE;
    }

  char sockbuf[256];
  int optlen = sizeof(sockbuf);

  if (SOCKET_ERROR != getsockopt((SOCKET)handle, SOL_SOCKET, SO_TYPE, sockbuf, &optlen) ||
      WSAENOTSOCK != WSAGetLastError())
    return CH_SOCKET;

  //assert(false);
  return CH_UNDEF;
}

int
cl_io::input_avail(void)
{
  //e_handle_type type= CH_UNDEF;
  //if (CH_UNDEF == type)
  //type = get_handle_type();

  switch (type)
    {
    case CH_SOCKET:
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

    case CH_FILE:
      return true;

    case CH_CONSOLE:
      {
        PINPUT_RECORD pIRBuf;
        DWORD NumPending;
        DWORD NumPeeked;
	
        /*
         * Peek all pending console events
         */
	//printf("win iput check on console id=%d handle=%p\n", file_id, handle);
        if (INVALID_HANDLE_VALUE == handle ||
	    !GetNumberOfConsoleInputEvents(handle, &NumPending) ||
	    NumPending == 0 ||
	    NULL == (pIRBuf = (PINPUT_RECORD)_alloca(NumPending * sizeof(INPUT_RECORD))))
          return false;
	
        if (PeekConsoleInput(handle, pIRBuf, NumPending, &NumPeeked) &&
	    NumPeeked != 0L &&
	    NumPeeked <= NumPending)
          {
            /*
             * Scan all of the peeked events to determine if any is a key event
             * which should be recognized.
             */
            for ( ; NumPeeked > 0 ; NumPeeked--, pIRBuf++ )
              {
                if (KEY_EVENT == pIRBuf->EventType &&
		    pIRBuf->Event.KeyEvent.bKeyDown &&
		    pIRBuf->Event.KeyEvent.uChar.AsciiChar)
                  return true;
              }
          }
	
        return false;
      }
      
    case CH_SERIAL:
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
      handle= INVALID_HANDLE_VALUE;
      type= CH_UNDEF;
    }
  else if (server_port > 0)
    {
      //printf("win socket id=%d\n", file_id);
      handle= (void*)file_id;
      type= CH_SOCKET;
    }
  else
    {
      //printf("win opened file id=%d\n", file_id);
      handle= (HANDLE)_get_osfhandle(file_id);
      type= get_handle_type();
      //printf("win handle=%p type=%d\n", handle, type);
    }
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
  //printf("win srv_accept(port=%d,sock=%d)\n", server_port, new_sock);
  if (fin)
    {
      class cl_io *io= new cl_io();
      if (new_sock > 0)
	{
	  int fh= _open_osfhandle((intptr_t)new_sock, _O_TEXT);
	  if (fh > 0)
	    {
	      FILE *f= fdopen(fh, "r");
	      //printf("fdopened f=%p for fh=%d as input\n", f, fh);
	      io->init(f, cchars("r"));
	      io->type= CH_SOCKET;
	    }
	}
      *fin= io;
    }

  if (fout)
    {
      class cl_io *io= new cl_io();
      if (new_sock > 0)
	{
	  int fh= _open_osfhandle((intptr_t)new_sock, _O_TEXT);
	  if (fh > 0)
	    {
	      FILE *f= fdopen(fh, "w");
	      //printf("fdopened f=%p for fh=%d as output\n", f, fh);
	      io->init(f, cchars("w"));
	      io->type= CH_SOCKET;
	    }
	}
      *fout= io;
    }

  return 0;
}


/* End of fwio.cc */
