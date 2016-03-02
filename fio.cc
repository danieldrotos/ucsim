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
#include <ctype.h>

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
  echo_of= NULL;
  echo_to= NULL;
  at_end= 0;
  last_used= first_free= 0;
  cooking= 0;
  line[0]= 0;
  cursor= 0;
  esc_buffer[0]= 0;
  attributes_saved= 0;
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
  echo_of= NULL;
  echo_to= NULL;
  at_end= 0;
  last_used= first_free= 0;
  cooking= 0;
  line[0]= 0;
  cursor= 0;
  esc_buffer[0]= 0;
  attributes_saved= 0;
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
  echo_of= NULL;
  echo_to= NULL;
  at_end= 0;
  last_used= first_free= 0;
  cooking= 0;
  line[0]= 0;
  cursor= 0;
  esc_buffer[0]= 0;
  attributes_saved= 0;
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
	  save_attributes();
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
}

int
cl_f::close(void)
{
  int i= 0;

  printf("close fid=%d\n", file_id);
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
  printf("stop_use fid=%d\n", file_id);
  file_f= NULL;
  file_id= -1;
  own= false;
  file_name= 0;
  file_mode= 0;
  attributes_saved= 0;
  changed();
  return 0;
}

cl_f::~cl_f(void)
{
  if (echo_of != NULL)
    echo_of->echo(NULL);
  if (file_f)
    {
      if (own)
	close();
      else
	stop_use();
    }
}


/* Buffer handling */

int
cl_f::put(char c)
{
  int n= (first_free + 1) % 1024;
  if (n == last_used)
    return -1;
  buffer[first_free]= c;
  first_free= n;
  /*
  {
    int p= last_used;
    printf("\nbuffer:\"");
    while (p != first_free)
      {
	printf("%c", buffer[p]);
	p= (p+1)%1024;
      }
    printf("\"\n");
  }
  */
  return 0;
}

int
cl_f::get(void)
{
  if (last_used == first_free)
    return -1;
  char c= buffer[last_used];
  if (c == 3 /* ^C */)
    return -2;
  last_used= (last_used + 1) % 1024;
  //printf("get: %d/%c\n", c, (c>31)?c:'.');
  return c;
}

int
cl_f::process_esc(char c)
{
  if (esc_buffer[0] == '\033')
    {
      int l= strlen(esc_buffer);
      esc_buffer[l]= c;
      l++;
      esc_buffer[l]= 0;
      if (esc_buffer[1] != '[')
	{
	  esc_buffer[0]= 0;
	  return c;
	}
      if (isalpha((int)c))
	{
	  esc_buffer[0]= 0;
	  switch (c)
	    {
	    case 'A':
	      return TU_UP;
	    case 'B':
	      return TU_DOWN;
	    case 'C':
	      return TU_RIGHT;
	    case 'D':
	      return TU_LEFT;
	    }
	}
      else if (c == '~')
	{
	  int n;
	  esc_buffer[0]= 0;
	  n= strtol(&esc_buffer[2], 0, 0);
	  switch (n)
	    {
	    case 1: return TU_HOME;
	    case 2: return TU_INS;
	    case 3: return TU_DEL;
	    case 4: return TU_END;
	    case 5: return TU_PGUP;
	    case 6: return TU_PGDOWN;
	    case 11: return TU_F1;
	    case 12: return TU_F2;
	    case 13: return TU_F3;
	    case 14: return TU_F4;
	    case 15: return TU_F5;
	    case 17: return TU_F6;
	    case 18: return TU_F7;
	    case 19: return TU_F8;
	    case 20: return TU_F9;
	    case 21: return TU_F10;
	    case 23: return TU_F11;
	    case 24: return TU_F12;
	    }
	}
      else
	return 0;
    }
  else
    {
      if (c == '\033')
	{
	  esc_buffer[0]= '\033', esc_buffer[1]= 0;
	  return 0;
	}
    }
  return c;
}

int
cl_f::process(char c)
{
  int i;
  unsigned int ci= c&0xff;
  
  if (!cooking)
    {
      printf("non-cooking echo %02x to fid=%d\n", ci, echo_to?(echo_to->file_id):-1);
      if ((ci<31) &&
	  (ci!='\n') &&
	  (ci!='\r'))
	{
	  char s[3]= "^ ";
	  s[1]= 'A'+ci-1;
	  echo_write_str(s);
	}
      else if (ci >= 127)
	{
	  char s[100];
	  sprintf(s, "\\%02x", ci);
	  echo_write_str(s);
	}
      else
	{
	  echo_write(&c, 1);
	}
      return put(c);
    }
  //return put(c);
  int l= strlen(line);
  int k= process_esc(c);
  int ret= 0;
  /*if (!k || tu_ready)
    return;*/
  if (!k)
    return 0;
  // CURSOR MOVEMENT
  if (k == TU_LEFT)
    {
      if (cursor > 0)
	{
	  cursor--;
	  echo_cursor_go_left(1);
	}
    }
  else if (k == TU_RIGHT)
    {
      if (line[cursor] != 0)
	{
	  cursor++;
	  echo_cursor_go_right(1);
	}
    }
  else if ((k == TU_HOME) ||
	   (k == 'A'-'A'+1))
    {
      if (cursor > 0)
	{
	  echo_cursor_go_left(cursor);
	  cursor= 0;
	}
    }
  else if ((k == TU_END) ||
	   (k == 'E'-'A'+1))
    {
      if (line[cursor] != 0)
	{
	  echo_cursor_go_right(l-cursor);
	  cursor= l;
	}
    }
  // FINISH EDITING
  else if ((k == 'C'-'A'+1) ||
	   (k == 'D'-'A'+1))
    {
      //ready= 1;
      at_end= 1;
    }
  else if ((k == '\n') ||
	   (k == '\r'))
    {
      //ready= 1;
      for (i= 0; i<l; i++)
	put(line[i]);
      put('\n');
      //tu_cooked();
      line[cursor= 0]= 0;
      esc_buffer[0]= 0;
      ret= l+1;
      echo_write_str("\n");
    }
  // DELETING
  else if (k == 8 /*BS*/)
    {
      if (cursor > 0)
	{
	  for (i= cursor; line[i]; i++)
	    line[i-1]= line[i];
	  l--;
	  line[l]= 0;
	  cursor--;
	  echo_cursor_go_left(1);
	  echo_cursor_save();
	  if (line[cursor])
	    //printf("%s ", &line[cursor]), fflush(stdout);
	    echo_write_str(&line[cursor]);
	  else
	    //write(STDOUT_FILENO, " ", 1);
	    echo_write_str(" ");
	  echo_cursor_restore();
	}
    }
  else if ((k == 127) || /*DEL*/
	   (k == TU_DEL))
    {
      if (line[cursor] != 0)
	{
	  for (i= cursor+1; line[i]; i++)
	    line[i-1]= line[i];
	  l--;
	  line[l]= 0;
	  echo_cursor_save();
	  if (line[cursor])
	    //printf("%s ", &line[cursor]), fflush(stdout);
	    echo_write_str(&line[cursor]);
	  else
	    //write(STDOUT_FILENO, " ", 1);
	    echo_write_str(" ");
	  echo_cursor_restore();
	}
    }
  else if (k == 'K'-'A'+1)
    {
      if (cursor > 0)
	echo_cursor_go_left(cursor);
      echo_cursor_save();
      while (l--)
	//write(STDOUT_FILENO, " ", 1);
	echo_write_str(" ");
      echo_cursor_restore();
      line[cursor= 0]= 0;
    }
  else if (k < 0)
    ;
  else if (isprint(k))
    {
      if (l < /*tu_buf_size*/1023)
	{
	  if (line[cursor] == 0)
	    {
	      line[cursor++]= k;
	      line[cursor]= 0;
	      echo_write(&c, 1);
	    }
	  else
	    {
	      int j;
	      for (j= l; j>=cursor; j--)
		line[j+1]= line[j];
	      line[cursor++]= k;
	      echo_cursor_save();
	      echo_write(&line[cursor-1], l-cursor+2);
	      echo_cursor_restore();
	      echo_cursor_go_right(1);
	    }
	}
    }
  return ret;
}

int
cl_f::pick(void)
{
  char b[100];
  int i= ::read(file_id, b, 99);
  if (i > 0)
    {
      int j;
      for (j= 0; j < i; j++)
	{
	  if (b[j] == 3 /* ^C */)
	    {
	      buffer[last_used= first_free= 0]= 3; // drop everything
	      at_end= 1;
	      return 0;
	    }
	  /*put*/process(b[j]);
	}
    }
  if (i == 0)
    at_end= 1;
  if (i < 0)
    printf("read error %d on fid=%d\n", i, file_id);
  return i;
}

int
cl_f::pick(char c)
{
  int i= /*put*/process(c);
  return i;
}

int
cl_f::input_avail(void)
{
  return check_dev();
}

int
cl_f::read(char *buf, int max)
{
  return read_dev(buf, max);
}


/* IO primitives */

int
cl_f::read_dev(char *buf, int max)
{
  int i= 0, c;
  
  if (max == 0)
    return -1;

  while (i < max)
    {
      c= get();
      if (c == -2)
	return i;
      if (c < 0)
	return (i==0)?-1:i;
      buf[i]= c;
      i++;
    }
  return (i==0)?-1:i;
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
  return at_end;//feof(file_f);
}


void
cl_f::flush(void)
{
  if (file_f)
    fflush(file_f);
}


/* Echoing */

void
cl_f::echo_cursor_save()
{
  if (echo_to)
    {
      echo_to->write(cchars("\033[s"), 3);
      echo_to->flush();
    }
}

void
cl_f::echo_cursor_restore()
{
  if (echo_to)
    {
      echo_to->write(cchars("\033[u"), 3);
      echo_to->flush();
    }
}

void
cl_f::echo_cursor_go_left(int n)
{
  char b[100];
  if (echo_to)
    {
      snprintf(b, 99, "\033[%dD", n);
      echo_to->write_str(b);
      echo_to->flush();
    }
}

void
cl_f::echo_cursor_go_right(int n)
{
  char b[100];
  if (echo_to)
    {
      snprintf(b, 99, "\033[%dC", n);
      echo_to->write_str(b);
      echo_to->flush();
    }
}

void
cl_f::echo_write(char *b, int l)
{
  if (echo_to)
    {
      echo_to->write(b, l);
      echo_to->flush();
    }
}

void
cl_f::echo_write_str(char *s)
{
  if (echo_to)
    {
      echo_to->write_str(s);
      echo_to->flush();
    }
}

void
cl_f::echo_write_str(const char *s)
{
  if (echo_to)
    {
      echo_to->write_str(s);
      echo_to->flush();
    }
}

  
/* Device handling */

void
cl_f::set_attributes()
{
}

void
cl_f::save_attributes()
{
}

void
cl_f::restore_attributes()
{
  printf("cl_f::restore_attr fid=%d\n", file_id);
}

int
cl_f::raw(void)
{
  cooking= 0;
  return 0;
}


int
cl_f::cooked(void)
{
  if (tty)
    {
      cooking= 1;
      line[cursor= 0]= 0;
      esc_buffer[0]= 0;
    }
  else
    {
      printf("Can not cook on non-tty %d\n", file_id);
    }
  return 0;
}

int
cl_f::echo(class cl_f *out)
{
  if (echo_to)
    {
      echo_to->echo_of= NULL;
      echo_to= NULL;
    }
  if (out != NULL)
    {
      printf("fid=%d echoing to fid=%d\n", file_id, out->file_id);
      out->echo_of= this;
      echo_to= out;
    }
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
