
#include "ddconfig.h"

#include <stdio.h>
#if defined HAVE_SYS_SOCKET_H
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#endif

#include "fuiocl.h"


int
cl_io::close(void)
{
  int i= 0;

  if (server_port)
    {
      shutdown(file_id, 2/*SHUT_RDWR*/);
    }
  if (file_f)
    {
      i= fclose(file_f);
    }
  file_f= NULL;
  file_id= -1;
  own= false;
  file_name= 0;
  file_mode= 0;
  changed();
  return i;
}

int
make_server_socket(int port)
{
  int sock, i;
  struct sockaddr_in name;

  /* Create the socket. */
  sock= socket(PF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    {
      perror("socket");
      return(0);
    }

  /* Give the socket a name. */
  i= 1;
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&i, sizeof(i)) < 0)
    {
      perror("setsockopt");
    }
  name.sin_family     = AF_INET;
  name.sin_port       = htons(port);
  name.sin_addr.s_addr= htonl(INADDR_ANY);
  if (bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0)
    {
      perror("bind");
      return(0);
    }

  return(sock);
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

  io= new cl_io(server_port);
  io->init();
  return io;
}


int
srv_accept(int server_port, int new_sock,
	   class cl_f **fin, class cl_f **fout)
{
  return 0;
}

/* End of fuio.cc */
