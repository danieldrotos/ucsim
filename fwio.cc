#include "fwiocl.h"

#ifdef SOCKET_AVAIL
# include HEADER_SOCKET
#endif

#include <windows.h>
#include <io.h>


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
  if (file_id < 0)
    {
      handle= INVALID_HANDLE_VALUE;
      type= CH_UNDEF;
    }
  else
    {
      //printf("win opened file id=%d\n", file_id);
      handle= (HANDLE)_get_osfhandle(file_id);
      type= get_handle_type();
      //printf("win handle=%p type=%d\n", handle, type);
    }
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


/* End of fwio.cc */
