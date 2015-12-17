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

#include "fiocl.h"


cl_f::cl_f(void)
{
  file_f= NULL;
  file_id= -1;
  own= false;
  tty= false;
  file_name= NULL;
  file_mode= NULL;
}

cl_f::cl_f(char *fn, char *mode):
  cl_base()
{
  file_f= NULL;
  file_id= -1;
  file_name= fn;
  file_mode= mode;
  tty= false;
  own= false;
}


int
cl_f::init(void)
{
  if ((file_f= fopen(file_name, file_mode)) != NULL)
    {
      file_id= fileno(file_f);
      tty= isatty(file_id);
      own= true;
    }
  else
    {
      file_id= -1;
      own= false;
    }
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

int
cl_f::use_opened(int opened_file_id, char *mode)
{
  close();
  if (mode)
    file_mode= mode;
  own= false;
  if (opened_file_id >= 0)
    {
      file_f= fdopen(opened_file_id, mode);
      if (file_f != NULL)
	{
	  file_id= opened_file_id;
	  tty= isatty(file_id);
	}
      else
	file_id= -1;
    }
  return file_id;
}

int
cl_f::close(void)
{
  int i;

  if (file_f)
    {
      i= fclose(file_f);
      file_f= NULL;
      file_id= -1;
      own= false;
    }
  return i;
}

int
cl_f::stop_use(void)
{
  file_f= NULL;
  file_id= -1;
  own= false;
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
  return ::read(file_id, buf, max);
}


int
cl_f::write(char *buf, int count)
{
  return ::write(file_id, buf, count);
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


int
cl_f::input_avail(void)
{
  struct timeval tv= { 0, 0 };
  fd_set s;
  int i;

  if (file_id<0)
    return 0;
  if (!tty)
    return 1;
  
  FD_ZERO(&s);
  FD_SET(file_id, &s);
  i= select(FD_SETSIZE, &s, NULL, NULL, &tv);
  printf("select(%d)=%d: (%d) %s\n",file_id,i,errno,strerror(errno));
  if (i >= 0)
    {
      return FD_ISSET(file_id, &s);
    }
  return 0;
}


/* End of fio.cc */
