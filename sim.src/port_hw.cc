/* $Id$ */

#include <ctype.h>

#include "globals.h"

#include "port_hwcl.h"


static const char *keysets[7]= {
  "12345678",
  "qwertyui",
  "asdfghjk",
  "zxcvbnm,",
  "QWERTYUI",
  "ASDFGHJK",
  "ZXCVBNM."
};

cl_port_hw::cl_port_hw(class cl_uc *auc, int aid, chars aid_string):
  cl_hw(auc, HW_PORT, aid, aid_string)
{
}


void
cl_port_hw::make_io()
{
  io= new cl_port_io(this);
  io->init();
  application->get_commander()->add_console(io);
}


void
cl_port_hw::new_io(class cl_f *f_in, class cl_f *f_out)
{
  cl_hw::new_io(f_in, f_out);
  if (io && io->get_fout())
    {
      // enable mouse click reports of terminal
      io->dd_printf("\033[1;2'z");
      io->dd_printf("\033[?9h");
      io->dd_printf("\033[3 q");
    }
}


void
cl_port_hw::proc_input(void)
{
  char c;
  class cl_f *fin, *fout;
  class cl_port_io *pio= (class cl_port_io *)io;

  fin= io->get_fin();
  fout= io->get_fout();

  if (fin->eof())
    {
      if (fout &&
	  (fout->file_id == fin->file_id))
	{
	  delete fout;
	  io->replace_files(false, fin, 0);
	}
      delete fin;
      io->replace_files(false, 0, 0);
      return;
    }
  fin->read(&c, 1);
  if (pio->keyset >= 0)
    {
      int i;
      for (i= 0; keysets[pio->keyset][i]; i++)
	if (keysets[pio->keyset][i] == c)
	  {
	    t_mem m= cell_in->read();
	    cell_in->write(m ^ (1<<(7-i)));
	    return;
	  }
    }
  pio->tu_go(1,1);
  //pio->tu_cll();
  //pio->dd_printf("Unknown command: %c (%d,0x%02x)\n", isprint(c)?c:'?', c, c);
}

void
cl_port_hw::refresh_display(bool force)
{
  class cl_port_io *pio= (class cl_port_io *)io;
  if (!io)
    return;
  if (force ||
      (cell_p->get() != cache_p))
    {
      cache_p= cell_p->get();
      pio->tu_go(pio->basx+4, pio->basy);
      int m= 0x80;
      for ( ; m; m>>= 1)
	pio->dd_printf("%c", (cache_p&m)?'*':'-');
      pio->tu_go(pio->basx+4+8+1, pio->basy);
      pio->dd_printf("%02x", cache_p);
    }
  if (force ||
      (cell_in->get() != cache_in))
    {
      cache_in= cell_in->get();
      pio->tu_go(pio->basx+4, pio->basy+2);
      int m= 0x80;
      for ( ; m; m>>= 1)
	pio->dd_printf("%c", (cache_in&m)?'*':'-');
      pio->tu_go(pio->basx+4+8+1, pio->basy+2);
      pio->dd_printf("%02x", cache_in);
    }
  pio->tu_go(1, 1);
}

void
cl_port_hw::draw_display(void)
{
  class cl_port_io *pio= (class cl_port_io *)io;
  if (!io)
    return;
  pio->tu_cls();
  pio->tu_go(pio->basx, pio->basy);
  pio->dd_printf("Out:");
  pio->tu_go(pio->basx, pio->basy+1);
  pio->dd_printf("Bit:76543210");
  pio->tu_go(pio->basx, pio->basy+2);
  pio->dd_printf("In :");
  pio->tu_go(pio->basx, pio->basy+3);
  pio->dd_printf("Key:%s", keysets[pio->keyset]);

  cache_p= cell_p->get();
  cache_in= cell_in->read();

  refresh_display(true);
}


/* IO console for port display */

cl_port_io::cl_port_io(class cl_hw *ihw):
  cl_hw_io(ihw)
{
  set_name("port");
}

int
cl_port_io::init(void)
{
  cl_hw_io::init();
  basx= 1;
  basy= 3+(hw->id*5);
  keyset= (hw->id) % 4;
  return 0;
}

/*
bool
cl_port_io::input_avail(void)
{
  if (hw)
    hw->refresh_display(false);
  return cl_console::input_avail();
}
*/

/* End of sim.src/port_hw.cc */
