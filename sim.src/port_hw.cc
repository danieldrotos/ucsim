/* $Id$ */

#include "port_hwcl.h"


cl_port_hw::cl_port_hw(class cl_uc *auc, int aid, chars aid_string):
  cl_hw(auc, HW_PORT, aid, aid_string)
{
}

void
cl_port_hw::proc_input(void)
{
  char c;
  class cl_f *fin, *fout;

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
  if (c == 'a')
    {
      t_mem m= cell_in->read();
      cell_in->write(m ^ 1);
    }
}

void
cl_port_hw::refresh_display(bool force)
{
  if (!io)
    return;
  if (force ||
      (cell_p->get() != cache_p))
    {
      cache_p= cell_p->get();
      io->dd_printf("Out: %x\n", cache_p);
    }
  if (force ||
      (cell_in->get() != cache_in))
    {
      cache_in= cell_in->get();
      io->dd_printf("In: %x\n", cache_in);
    }
}

void
cl_port_hw::draw_display(void)
{
}

bool
cl_port_io::input_avail(void)
{
  if (hw)
    hw->refresh_display(false);
  return cl_console::input_avail();
}


/* End of sim.src/port_hw.cc */
