/* $Id$ */

#include <ctype.h>

#include "globals.h"

#include "port_hwcl.h"


const char *keysets[7]= {
  "12345678",
  "qwertyui",
  "asdfghjk",
  "zxcvbnm,",
  "QWERTYUI",
  "ASDFGHJK",
  "ZXCVBNM."
};


cl_port_ui::cl_port_ui(class cl_uc *auc, int aid, chars aid_string):
  cl_hw(auc, HW_DUMMY, aid, aid_string)
{
  int i;
  
  for (i= 0; i < NUOF_PORT_UIS; i++)
    {
      pd[i].init();
      pd[i].cell_p= NULL;
      pd[i].cell_in= NULL;
      pd[i].cache_p= 0;
      pd[i].cache_in= 0;
      pd[i].keyset= NULL;
    }
}


bool
cl_port_ui::add_port(class cl_port_data *p, int nr)
{
  if (nr >= NUOF_PORT_UIS)
    return false;
  if (pd[nr].cell_p)
    return false;

  pd[nr].cell_p  = p->cell_p;
  pd[nr].cell_in = p->cell_in;
  pd[nr].cache_p = p->cache_p;
  pd[nr].cache_in= p->cache_in;
  pd[nr].keyset  = p->keyset;
  pd[nr].basx    = p->basx;
  pd[nr].basy    = p->basy;

  pd[nr].set_name(p->get_name());
  
  return true;
}


void
cl_port_ui::make_io()
{
  io= new cl_port_io(this);
  io->init();
  application->get_commander()->add_console(io);
}


void
cl_port_ui::new_io(class cl_f *f_in, class cl_f *f_out)
{
  cl_hw::new_io(f_in, f_out);
  io->tu_mouse_on();
}


bool
cl_port_ui::proc_input(void)
{
  return cl_hw::proc_input();
}

bool
cl_port_ui::handle_input(char c)
{
  class cl_port_io *pio= (class cl_port_io *)io;
  int i;

  for (i= 0; i < NUOF_PORT_UIS; i++)
    {
      if (pd[i].cell_p == NULL)
	continue;
	
      if (pd[i].keyset != NULL)
	{
	  int bit;
	  for (bit= 0; pd[i].keyset[bit]; bit++)
	    if (pd[i].keyset[bit] == c)
	      {
		t_mem m= pd[i].cell_in->read();
		pd[i].cell_in->write(m ^ (1<<(7-bit)));
		pio->tu_go(1,1);
		return true;
	      }
	}
    }
  pio->tu_go(1,24);
  pio->tu_cll();
  int ret= cl_hw::handle_input(c); // handle default keys
  pio->tu_go(1,1);
  //pio->tu_cll();
  //pio->dd_printf("Unknown command: %c (%d,0x%02x)\n", isprint(c)?c:'?', c, c);
  return ret;
}

void
cl_port_ui::refresh_display(bool force)
{
  class cl_port_io *pio= (class cl_port_io *)io;
  if (!io)
    return;
  int i;
  for (i= 0; i < NUOF_PORT_UIS; i++)
    {
      if (pd[i].cell_p == NULL)
	continue;
      if (force ||
	  (pd[i].cell_p->get() != pd[i].cache_p))
	{
	  pd[i].cache_p= pd[i].cell_p->get();
	  pio->tu_go(pd[i].basx+4, pd[i].basy+1);
	  int m= 0x80;
	  for ( ; m; m>>= 1)
	    pio->dd_printf("%c", (pd[i].cache_p&m)?'*':'-');
	  pio->tu_go(pd[i].basx+4+8+1, pd[i].basy+1);
	  pio->dd_printf("%02x", pd[i].cache_p);
	}
      if (force ||
	  (pd[i].cell_in->get() != pd[i].cache_in))
	{
	  pd[i].cache_in= pd[i].cell_in->get();
	  pio->tu_go(pd[i].basx+4, pd[i].basy+3);
	  int m= 0x80;
	  for ( ; m; m>>= 1)
	    pio->dd_printf("%c", (pd[i].cache_in&m)?'*':'-');
	  pio->tu_go(pd[i].basx+4+8+1, pd[i].basy+3);
	  pio->dd_printf("%02x", pd[i].cache_in);
	}
    }
  cl_hw::refresh_display(force);
  pio->tu_go(1, 1);
}

void
cl_port_ui::draw_display(void)
{
  class cl_port_io *pio= (class cl_port_io *)io;
  if (!io)
    return;
  pio->tu_cls();

  cl_hw::draw_display();
  
  int i;
  for (i= 0; i < NUOF_PORT_UIS; i++)
    {
      if (pd[i].cell_p == NULL)
	continue;
      pio->tu_go(pd[i].basx, pd[i].basy);
      if (pd[i].have_real_name())
	pio->dd_printf(pd[i].get_name());
      else
	pio->dd_printf("port_%d", i);
      
      pio->tu_go(pd[i].basx, pd[i].basy+1);
      pio->dd_printf("Out:");
      pio->tu_go(pd[i].basx, pd[i].basy+2);
      pio->dd_printf("Bit:76543210");
      pio->tu_go(pd[i].basx, pd[i].basy+3);
      pio->dd_printf("In :");
      pio->tu_go(pd[i].basx, pd[i].basy+4);
      if (pd[i].keyset)
	pio->dd_printf("Key:%s", pd[i].keyset);

      pd[i].cache_p= pd[i].cell_p->get();
      pd[i].cache_in= pd[i].cell_in->read();
    }
  
  refresh_display(true);
}


/* IO console for port display */

cl_port_io::cl_port_io(class cl_hw *ihw):
  cl_hw_io(ihw)
{
}

int
cl_port_io::init(void)
{
  cl_hw_io::init();
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
