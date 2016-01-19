/*
 * Simulator of microcontrollers (fio.cc)
 *
 * Copyright (C) 1997,12 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#include "ddconfig.h"

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include HEADER_FD
#include <errno.h>
#include <string.h>
#if defined HAVE_SYS_SOCKET_H
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#endif
#include <stdlib.h>

#include "fiocl.h"

// prj
#include "utils.h"


cl_f::cl_f(void)
{
  file_f= NULL;
  file_id= -1;
  own= false;
  tty= false;
  file_name= 0;
  file_mode= 0;
  server_port= -1;
}

cl_f::cl_f(chars fn, chars mode):
  cl_base()
{
  file_f= NULL;
  file_id= -1;
  file_name= fn;
  file_mode= mode;
  tty= false;
  own= false;
  server_port= -1;
}

cl_f::cl_f(int the_server_port)
{
  file_f= NULL;
  file_id= -1;
  own= false;
  tty= false;
  file_name= 0;
  file_mode= 0;
  server_port= the_server_port;
}

class cl_f *
cl_f::copy(chars mode)
{
  class cl_f *io= mk_io(chars(""), chars(""));
  io->use_opened(file_id, mode);
  return io;
}

int
cl_f::init(void)
{
  if (server_port > 0)
    {
      file_id= mk_srv_socket(server_port);
      //printf("cl_f::init srv_port=%d file_id=%d\n", server_port, file_id);
      listen(file_id, 50);
      own= true;
      tty= false;
      changed();
    }
  else if (!file_name.empty())
    {
      if (file_mode.empty())
	file_mode= cchars("r+");
      if ((file_f= fopen(file_name, file_mode)) != NULL)
	{
	  file_id= fileno(file_f);
	  tty= isatty(file_id);
	  own= true;
	  changed();
	}
      else
	{
	  file_id= -1;
	  own= false;
	}
    }
  return file_id;
}

int
cl_f::use_opened(int opened_file_id, char *mode)
{
  close();
  if (mode)
    file_mode= mode;
  else
    file_mode= cchars("r+");
  own= false;
  if (opened_file_id >= 0)
    {
      file_f= fdopen(opened_file_id, file_mode);
      if (file_f != NULL)
	{
	  file_id= opened_file_id;
	  tty= isatty(file_id);
	  changed();
	}
      else
	file_id= -1;
    }
  return file_id;
}

int
cl_f::own_opened(int opened_file_id, char *mode)
{
  use_opened(opened_file_id, mode);
  own= true;
  return file_id;
}

int
cl_f::use_opened(FILE *f, chars mode)
{
  close();
  if (f)
    {
      file_mode= mode;
      file_f= f;
      file_id= fileno(file_f);
      tty= isatty(file_id);
      own= false;
      changed();
    }
  return file_id;
}

int
cl_f::own_opened(FILE *f, chars mode)
{
  use_opened(f, mode);
  own= true;
  return file_id;
}

int
cl_f::open(char *fn)
{
  close();
  if (fn)
    file_name= fn;
  return init();
}

int
cl_f::open(char *fn, char *mode)
{
  close();
  if (mode)
    file_mode= mode;
  if (fn)
    file_name= fn;
  return init();
}

void
cl_f::changed(void)
{
  if (file_id < 0)
    type= F_UNKNOWN;
  else
    type= determine_type();
}

int
cl_f::close(void)
{
  int i= 0;

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
cl_f::stop_use(void)
{
  file_f= NULL;
  file_id= -1;
  own= false;
  file_name= 0;
  file_mode= 0;
  changed();
  return 0;
}

cl_f::~cl_f(void)
{
  if (file_f)
    {
      if (own)
	close();
      else
	stop_use();
    }
}


/* IO primitives */

int
cl_f::read(char *buf, int max)
{
  if (file_id >= 0)
    {
      if (input_avail())
	return ::read(file_id, buf, max);
      else
	return -1;
    }
  return -1;
}


int
cl_f::write(char *buf, int count)
{
  if (file_id >= 0)
    return ::write(file_id, buf, count);
  return -1;
}


int
cl_f::write_str(char *s)
{
  //return fprintf(file_f, "%s", s);
  if (!s ||
      !*s)
    return 0;
  return ::write(file_id, s, strlen(s));
}


int
cl_f::write_str(const char *s)
{
  if (!s ||
      !*s)
    return 0;
  //return fprintf(file_f, "%s", s);
  return ::write(file_id, s, strlen(s));
}

int
cl_f::vprintf(char *format, va_list ap)
{
  char *s= vformat_string(format, ap);
  int i= write_str(s);
  free(s);
  return i;
}

bool
cl_f::eof(void)
{
  if (file_f == NULL)
    return true;
  return feof(file_f);
}


void
cl_f::flush(void)
{
  if (file_f)
    fflush(file_f);
}


/* Device handling */

int
cl_f::raw(void)
{
  return 0;
}


int
cl_f::cooked(void)
{
  return 0;
}


/* Socket functions */

/*
int
cl_f::listen(int on_port)
{
  return -1;
}
*/
/*
class cl_f *
cl_f::accept()
{
  return NULL;
}
*/
/*
int
cl_f::connect(chars host, int to_port)
{
  return -1;
}
*/

/* End of fio.cc */
