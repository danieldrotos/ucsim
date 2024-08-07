/*
 * Simulator of microcontrollers (cmd.src/newcmdposix.cc)
 *
 * Copyright (C) 1999 Drotos Daniel
 * Copyright (C) 2006, Borut Razem - borut.razem@siol.net
 *
 * To contact author send email to dr.dkdb@gmail.com
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

//#include "ddconfig.h"

#include <stdio.h>
#include <errno.h>
//#include <stdarg.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/time.h>
#include <string.h>
#include <unistd.h>

//#include "i_string.h"

// prj
#include "globals.h"
//#include "utils.h"

// sim
//#include "simcl.h"
//#include "argcl.h"

// local


/*
 * Command console
 *____________________________________________________________________________
 */

cl_console::cl_console(const char *_fin, const char *_fout, class cl_app *the_app)
{
  app= the_app;
  fin= 0;
  if (_fin)
    {
      fin= mk_io(_fin, "r");
    }
  fout= 0;
  if (_fout)
    {
      fout= mk_io(_fout, "w");
    }
  prompt= 0;
  set_flag(~CONS_NONE, false);
  if ((fin && fin->tty) && (fout && fout->tty))
    {
      set_interactive(true);
      fin->echo(fout);
      fin->cooked();
    }
  else
    {}
  frout= 0;
  id= 0;
  lines_printed= new cl_ustrings(100, 100, "console_cache");
}

cl_console::cl_console(cl_f *_fin, cl_f *_fout, class cl_app *the_app)
{
  app= the_app;
  fin= _fin;
  fout= _fout;
  prompt= 0;
  set_flag(~CONS_NONE, false);
  if ((fin && fin->tty) && (fout && fout->tty))
    {
      set_interactive(true);
      fin->echo(fout);
      fin->cooked();
    }
  else
    {}
  frout= 0;
  id= 0;
  lines_printed= new cl_ustrings(100, 100, "console_cache");
}

class cl_console_base *
cl_console::clone_for_exec(char *_fin)
{
  class cl_f *fi= 0, *fo= 0;

  if (!_fin)
    return(0);
  if (fi= mk_io(_fin, "r"), !fi)
    {
      fprintf(stderr, "Can't open `%s': %s\n", _fin, strerror(errno));
      return(0);
    }
  
  if ((fo= fout->copy("a")) == 0)
    {
      delete fi;
      fprintf(stderr, "Can't re-open output file: %s\n", strerror(errno));
      return(0);
    }
    
  class cl_console *con= new cl_sub_console(this, fi, fo, app);
  return(con);
}

void
cl_console::drop_files(void) // do not close, just ignore
{
  fin= 0;
  fout= 0;
  frout= 0;
  application->get_commander()->update_active();
}

void
cl_console::close_files(bool close_in, bool close_out)
{
  if (frout)
    delete frout;
  if (close_out)
    {
      if (fout)
	{
	  if (fout->tty)
	    tu_reset();
	  delete fout;
	}
      fout= 0;
    }
  if (close_in)
    {
      if (fin)
	delete fin;
      fin= 0;
      application->get_commander()->update_active();
    }
}

void
cl_console::replace_files(bool close_old, cl_f *new_in, cl_f *new_out)
{
  if (frout)
    delete frout;
  frout= 0;
  if (close_old)
    close_files(fin != new_in, fout != new_out);
  fin= new_in;
  fout= new_out;
  application->get_commander()->update_active();
}

cl_console::~cl_console(void)
{
  un_redirect();
  if (fout)
    {
      if (fout->tty)
	tu_reset();
      delete fout;
    }
  if (fin)
    {
      delete fin;
    }
}


/*
 * Output functions
 */

void
cl_console::redirect(const char *fname, const char *mode)
{
  frout= mk_io(fname, mode);
  set_flag(CONS_REDIRECTED, true);
}

void
cl_console::un_redirect(void)
{
  set_flag(CONS_REDIRECTED, false);
  if (!frout)
    return;
  delete frout;
  frout= 0;
}

/*
 * Input functions
 */

bool
cl_console::input_avail(void)
{
  bool ret= false;
  if (input_active())
    {
      ret= fin->input_avail();
    }
  return ret;
}

bool
cl_console::need_check(void)
{
  return fin && (fin->type == F_CONSOLE);
}

bool
cl_console::set_cooked(bool new_val)
{
  if (!fin)
    return false;
  if (new_val)
    {
      if (!fin->get_cooking())
	fin->interactive(fout);
    }
  else
    {
      // raw
      fin->raw();
    }
  return fin->get_cooking();
}


/* Return
   -1 if EOF (and buffer is empty) or ^C found
   0  buffer is not ready yet
   1  buffer filled (EOL detected)
*/

int
cl_console::read_line(void)
{
  int i= 0;
  int b[2]= { 0, 0 };

  do {
    i= fin->read(b, 1);
    if (i < -1)
      {
	return -1;
      }
    if (i == 0)
      {
	// EOF
	if (lbuf.len() == 0)
	  return -1;
	// execute last line, assuming \n
	return 1;
      }
    if (i > 0)
      {
	// Got a char
	if (b[0] == 3)
	  // ^C, drop and close
	  return -1;
	if ((b[0] == '\n') ||
	    (b[0] == '\r'))
	  {
	    if (nl &&
		(nl != b[0]))
	      {
		nl= 0;
		continue;
	      }
	    nl= b[0];
	    /*
	    if (lbuf.len() != 0)
	      {
		b[0]= '\n';
		lbuf+= b;
	      }
	    */
	    return 1;
	  }
	{
	  char s[2];
	  s[0]= b[0];
	  s[1]= b[1];
	  lbuf+= s;
	}
      }
  }
  while (i > 0);
  return 0;
}


/*
 * This console listen on a socket and can accept connection requests
 */
//#ifdef SOCKET_AVAIL

cl_listen_console::cl_listen_console(int serverport, class cl_app *the_app)
{
  app= the_app;
  fin= mk_srv(serverport);
  fout= frout= 0;
}

cl_listen_console::cl_listen_console(cl_f *_fin, class cl_app *the_app)
{
  app= the_app;
  fin= _fin;
  fout= frout= 0;
}

int
cl_listen_console::proc_input(class cl_cmdset *cmdset)
{
  class cl_commander_base *cmd;
  cl_f *in, *out;
  
  cmd= app->get_commander();

  srv_accept(fin, &in, &out);
  class cl_console_base *c= mk_console(in, out);
  cmd->add_console(c);
  return(0);
}

class cl_console_base *
cl_listen_console::mk_console(cl_f *fi, cl_f *fo)
{
  class cl_console_base *c= new cl_console(fi, fo, app);
  c->set_flag(CONS_INTERACTIVE, true);
  fi->interactive(fo);
  return c;
}


//#endif /* SOCKET_AVAIL */


/*
 * Sub-console
 */

cl_sub_console::cl_sub_console(class cl_console_base *the_parent,
                               class cl_f *fin, class cl_f *fout, class cl_app *the_app):
  cl_console(fin, fout, the_app)
{
  parent= the_parent;
}

cl_sub_console::~cl_sub_console(void)
{
  class cl_commander_base *c= app->get_commander();

  if (parent && c)
    {
      c->activate_console(parent);
    }
}

int
cl_sub_console::init(void)
{
  class cl_commander_base *c= app->get_commander();

  if (parent && c)
    {
      c->deactivate_console(parent);
    }
  cl_console::init();
  set_flag(CONS_ECHO, true);
  return(0);
}


/*
 * Command interpreter
 *____________________________________________________________________________
 */

int
cl_commander::init(void)
{
  class cl_optref console_on_option(this);
  class cl_optref config_file_option(this);
  class cl_optref port_number_option(this);
  class cl_optref default_port_option(this);
  
  class cl_console_base *con;
  int ccnt= 0;
  cl_console_base *c;
  
  console_on_option.init();
  console_on_option.use("console_on");
  config_file_option.init();
  config_file_option.use("config_file");
  port_number_option.init();
  default_port_option.init();
  
  cl_base::init();
  set_name("Commander");
  active_inputs= new cl_list(10, 5, "active_inputs");
  check_list= new cl_list(10, 5, "check_list");

  int def_port= 0;
  if (default_port_option.use("default_port"))
    {
      def_port= default_port_option.get_value((long)0);
    }
  if (def_port >= 1000)
    {
      cl_f *srv= mk_srv(def_port);
      if (srv->opened())
	{
	  c= new cl_listen_console(srv, app);
	  add_console(c);
	  c->prev_quit= 0;
	  ccnt++;
	}
      else delete srv;
    }
  
  if (port_number_option.use("port_number"))
    {
      c= new cl_listen_console(port_number_option.get_value((long)0), app);
      c->init();
      add_console(c);
    }
  if (app->rgdb_port > 0)
    {
      c= new cl_rgdb_listener(app->rgdb_port, app, app->sim);
      c->init();
      add_console(c);
    }

  char *Config= config_file_option.get_value("");
  char *cn= console_on_option.get_value("");

  if (cn)
    {
      if (strcmp(cn, "-") == 0)
	{
	  class cl_f *in, *out;
	  in= cp_io(fileno(stdin), "r");
	  out= cp_io(fileno(stdout), "w");
	  in->interactive(out);
	  add_console(con= new cl_console(in, out, app));
	  std_console= con;
	  if (in->tty)
	    con->set_flag(CONS_INTERACTIVE, true);
	}
      else
	{
	  class cl_f *in, *out;
	  in= mk_io(cn, "r");
	  if (!in)
	    fprintf(stderr, "Can not open %s\n", cn);
	  else
	    {
	      if (in->type == F_FILE)
		out= cp_io(fileno(stdout), "w");
	      else
		out= cp_io(in->file_id, "w");
	      add_console(con= new cl_console(in, out, app));
	    }
	}
    }
  if (cons->get_count() == ccnt)
    {
      class cl_f *in, *out;
      in= cp_io(fileno(stdin), "r");
      out= cp_io(fileno(stdout), "w");
      in->interactive(out);
      add_console(con= new cl_console(in, out, app));
      std_console= con;
      if (in->tty)
	con->set_flag(CONS_INTERACTIVE, true);
    }

  class cl_f *i= NULL, *o;
  if (Config &&
      *Config)
    {
      i= mk_io(Config, "r");
      if (i->file_id < 0)
	fprintf(stderr, "Error opening cfg file: %s\n", Config);
      else
	{
	  o= cp_io(fileno(stderr), "w");
	  con= new cl_console(i, o, app);
	  con->set_flag(CONS_NOWELCOME|CONS_ECHO, true);
	  config_console= con;
	  add_console(con);
	}
    }
  return(0);
}

void
cl_commander::update_active(void)
{
  int i;
  
  active_inputs->disconn_all();
  check_list->disconn_all();

  if (config_console)
    {
      if (!cons->index_of(config_console, NULL))
	{
	  config_console= 0;
	}
    }

  for (i= 0; i < cons->count; i++)
    {
      class cl_console *c=
	(class cl_console *)cons->at(i);
      class cl_f *f= c->get_fin();

      if (config_console &&
	  (config_console != c))
	continue;

      if (f &&
	  (f->file_id < 0))
	continue;
      
      if (c->input_active() &&
	  f)
	{
	  active_inputs->add(f);
	}
      if (c->need_check() &&
	  f)
	check_list->add(f);
    }
}

int
cl_commander::input_avail(void)
{
  class cl_list *avail= new cl_list(10,5,"avail");
  bool ret= check_inputs(active_inputs, avail);
  avail->disconn_all();
  delete avail;
  return ret;
}

int
cl_commander::proc_input(void)
{
  if (config_console)
    {
      if (!cons->index_of(config_console, NULL))
	config_console= 0;
    }
  
  for (int j = 0; j < cons->count; j++)
    {
      class cl_console *c =
	(class cl_console*)((class cl_console_base*)(cons->at(j)));
      class cl_f *f= c->get_fin();
      
      if (config_console &&
	  (config_console != c))
	continue;

      if (c->input_active() &&
	  f)
        {
	  if (c->input_avail())
            {
              actual_console = c;
              int retval = c->proc_input(cmdset);
              if (retval)
                {
                  del_console(c);
                  //delete c;
                }
              actual_console = 0;
	      int i= consoles_prevent_quit();
              return(i == 0);
            }
        }
    }
  return 0;
}


void
cl_commander::check(void)
{
  int i;

  for (i= 0; i < check_list->count; i++)
    {
      class cl_f *f= (class cl_f *)check_list->at(i);
      f->check();
    }
}

/* End of cmd.src/newcmdposix.cc */
