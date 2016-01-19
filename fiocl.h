/*
 * Simulator of microcontrollers (fiocl.h)
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

#ifndef FIOCL_HEADER
#define FIOCL_HEADER

#include <stdio.h>

#include "pobjcl.h"


enum file_type {
  F_UNKNOWN,
  F_FILE,
  F_CHAR,
  F_SOCKET,
  F_CONSOLE, // win only
  F_SERIAL // win only
};


/* General file */

class cl_f: public cl_base
{
 public:
  chars file_name, file_mode;
  int file_id;
  bool tty;
  bool own;
  enum file_type type;
 protected:
  FILE *file_f;
 public:
  cl_f(void);
  cl_f(chars fn, chars mode);
  cl_f(int the_server_port);
  virtual ~cl_f(void);
  virtual class cl_f *copy(chars mode);
  virtual int init(void);
  //virtual int open(void) { return init(); }
  virtual int open(char *fn);
  virtual int open(char *fn, char *mode);
  virtual int use_opened(int opened_file_id, char *mode);
  virtual int own_opened(int opened_file_id, char *mode);
  virtual int use_opened(FILE *f, chars mode);
  virtual int own_opened(FILE *f, chars mode);
  virtual enum file_type determine_type(void)= 0;
  virtual void changed(void);
  virtual int close(void);
  virtual int stop_use(void);
  
  FILE *f(void) { return file_f; };
  int id(void) { return file_id; };

  virtual int read(char *buf, int max);
  virtual int write(char *buf, int count);
  virtual int write_str(char *s);
  virtual int write_str(const char *s);
  virtual int vprintf(char *format, va_list ap);
  virtual bool eof(void);
  virtual void flush(void);
  
  virtual int raw(void);
  virtual int cooked(void);
  virtual int input_avail(void)= 0;

 public:
  int server_port;

 public:
  //virtual int listen(int on_port);
  //virtual class cl_f *accept();
  //virtual int connect(chars host, int to_port);
};


extern int mk_srv_socket(int port);

extern class cl_f *mk_io(chars fn, chars mode);
extern class cl_f *cp_io(FILE *f, chars mode);
extern class cl_f *mk_srv(int server_port);
extern int srv_accept(class cl_f *listen_io,
		      class cl_f **fin, class cl_f **fout);
extern void msleep(int msec);


#endif

/* End of fiocl.h */
