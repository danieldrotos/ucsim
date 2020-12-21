/*
 * Simulator of microcontrollers (port.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
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

#include <stdio.h>
#include <ctype.h>

// cmd
#include "argcl.h"

// local

#include "portcl.h"


cl_port::cl_port(class cl_uc *auc, int aid):
  cl_hw(auc, HW_PORT, aid, "port")
{
  base= 0xc010;
}

cl_port::cl_port(class cl_uc *auc, int aid, t_addr the_addr):
  cl_hw(auc, HW_PORT, aid, "port")
{
  base= the_addr;
}

int
cl_port::init(void)
{
  cl_hw::init();

  rs[0]= register_cell(uc->rom, base+0);
  rs[1]= register_cell(uc->rom, base+1);
  rs[2]= register_cell(uc->rom, base+2);
  rs[3]= register_cell(uc->rom, base+3);

  cra = cfg_cell(cfg_cra);
  ddra= cfg_cell(cfg_ddra);
  ora = cfg_cell(cfg_ora);
  ina = cfg_cell(cfg_ina);
  crb = cfg_cell(cfg_crb);
  ddrb= cfg_cell(cfg_ddrb);
  orb = cfg_cell(cfg_orb);
  inb = cfg_cell(cfg_inb);
  
  oca = cfg_cell(cfg_oca);
  ddca= cfg_cell(cfg_ddca);
  inca= cfg_cell(cfg_inca);
  ocb = cfg_cell(cfg_ocb);
  ddcb= cfg_cell(cfg_ddcb);
  incb= cfg_cell(cfg_incb);

  cl_var *v;
  chars pn= chars("", "port%d_", id);
  uc->vars->add(v= new cl_var(pn+chars("base"), cfg, cfg_base,
			      cfg_help(cfg_base)));
  v->init();
  
  uc->vars->add(v= new cl_var(pn+chars("on"), cfg, cfg_on,
			      cfg_help(cfg_on)));
  v->init();

  uc->vars->add(v= new cl_var(pn+chars("cra"), cfg, cfg_cra,
			      cfg_help(cfg_cra)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ddra"), cfg, cfg_ddra,
			      cfg_help(cfg_ddra)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ora"), cfg, cfg_ora,
			      cfg_help(cfg_ora)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ina"), cfg, cfg_ina,
			      cfg_help(cfg_ina)));
  v->init();

  uc->vars->add(v= new cl_var(pn+chars("crb"), cfg, cfg_crb,
			      cfg_help(cfg_cra)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ddrb"), cfg, cfg_ddrb,
			      cfg_help(cfg_ddra)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("orb"), cfg, cfg_orb,
			      cfg_help(cfg_ora)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("inb"), cfg, cfg_inb,
			      cfg_help(cfg_ina)));
  v->init();

  uc->vars->add(v= new cl_var(pn+chars("oca"), cfg, cfg_oca,
			      cfg_help(cfg_oca)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ddca"), cfg, cfg_ddca,
			      cfg_help(cfg_ddca)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("inca"), cfg, cfg_inca,
			      cfg_help(cfg_inca)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ocb"), cfg, cfg_ocb,
			      cfg_help(cfg_ocb)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("ddcb"), cfg, cfg_ddcb,
			      cfg_help(cfg_ddcb)));
  v->init();
  uc->vars->add(v= new cl_var(pn+chars("incb"), cfg, cfg_incb,
			      cfg_help(cfg_incb)));
  v->init();

  return(0);
}

void
cl_port::reset(void)
{
  cra->write(0);
  ddra->write(0);
  ora->write(0);
  crb->write(0);
  ddrb->write(0);
  orb->write(0);

  oca->write(2);
  ocb->write(2);

  prev_ca1= ca1();
  prev_ca2= ca2();
  prev_cb1= cb1();
  prev_cb2= cb2();
}

const char *
cl_port::cfg_help(t_addr addr)
{
  switch ((enum port_cfg)addr)
    {
    case cfg_on		: return "Turn/get on/off state (bool, RW)";
    case cfg_base	: return "Base address of the port (int, RW)";
    case cfg_cra	: return "CRA  - Control Register A (int, RW)";
    case cfg_ddra	: return "DDRA - Data Direction Register A (int, RW)";
    case cfg_ora	: return "ORA  - Peripheral Register A (int, RW)";
    case cfg_ina	: return "ina  - Outside value of port A pins (int, RW)";
    case cfg_crb	: return "CRB  - Control Register B (int, RW)";
    case cfg_ddrb	: return "DDRB - Data Direction Register B (int, RW)";
    case cfg_orb	: return "ORB  - Peripheral Register B (int, RW)";
    case cfg_inb	: return "inb  - Outside value of port B pins (int, RW)";
    case cfg_oca	: return "oca  - Output value of port CA (int, RW)";
    case cfg_ddca	: return "ddca - Direction of port CA (int, RW)";
    case cfg_inca	: return "inca - Outside value of port CA pins (int, RW)";
    case cfg_ocb	: return "ocb  - Output value of port CB (int, RW)";
    case cfg_ddcb	: return "ddcb - Direction of port CB (int, RW)";
    case cfg_incb	: return "incb - Outside value of port CB pins (int, RW)";
    }
  return "Not used";
}

class cl_memory_cell *
cl_port::reg(class cl_memory_cell *cell_rs)
{
  if (cell_rs == rs[0])
    {
      if (cra->get() & 4)
	return ora;
      else
	return ddra;
    }
  else if (cell_rs == rs[1])
    return cra;
  else if (cell_rs == rs[2])
    {
      if (crb->get() & 4)
	return orb;
      else
	return ddrb;
    }
  else if (cell_rs == rs[3])
    return crb;
  return NULL;
}

t_mem
cl_port::read(class cl_memory_cell *cell)
{
  class cl_memory_cell *r= reg(cell);
  conf(cell, NULL);
  if (r != NULL)
    {
      u8_t i, o, d;
      if (r == ora)
	{
	  cra->set(cra->get() & 0x3f);
	  d= ddra->get();
	  i= ina->get();
	  o= ora->get();
	  return (~d&i) | (d&o&i);
	}
      if (r == orb)
	{
	  crb->set(crb->get() & 0x3f);
	  d= ddrb->get();
	  i= inb->get();
	  o= orb->get();
	  return (~d&i) | (d&o);	    
	}
      return r->get();
    }
  return cell->get();
}

void
cl_port::write(class cl_memory_cell *cell, t_mem *val)
{
  class cl_memory_cell *r= reg(cell);
  if (val)
    {
      // Is CPU allowed to trigger IRQ?
      if (r == cra || r == crb)
	{
	  *val&= 0x3f;
	  if (r->get() & 0x80) *val|= 0x80;
	  if (r->get() & 0x40) *val|= 0x40;
	}
    }
  conf(cell, val);
  if (r == NULL)
    return;
  r->set(*val);
}

t_mem
cl_port::conf_op(cl_memory_cell *cell, t_addr addr, t_mem *val)
{
  t_mem v;
  class cl_memory_cell *r= NULL;
  switch ((enum port_cfg)addr)
    {
    case cfg_on	:  // turn this HW on/off
      if (val)
	{
	  if (*val)
	    on= true;
	  else
	    on= false;
	}
      v= on?1:0;
      cell->set(v);
      break;
    case cfg_base:
      if (val)
	{
	  int i;
	  if (uc->rom->valid_address(*val))
	    {
	      for (i= 0; i < 3; i++)
		unregister_cell(rs[i]);
	      base= *val;
	      init();
	    }
	}
      cell->set(base);
      break;
    case cfg_cra	: r= cra;
      if (val && (*val&0x80) && !(r->get() & 0x80))
	{
	  // TODO: IRQ by CA1
	}
      if (val && (*val&0x40) && !(r->get() & 0x40))
	{
	  // TODO: IRQ by CA2
	}
      break;
    case cfg_ddra	: r= ddra; break;
    case cfg_ora	: r= ora; break;
    case cfg_ina	: r= ina; break;
    case cfg_crb	: r= crb;
      if (val && (*val&0x80) && !(r->get() & 0x80))
	{
	  // TODO: IRQ by CB1
	}
      if (val && (*val&0x40) && !(r->get() & 0x40))
	{
	  // TODO: IRQ by CB2
	}
      break;
    case cfg_ddrb	: r= ddrb; break;
    case cfg_orb	: r= orb; break;
    case cfg_inb	: r= inb; break;

    case cfg_oca	: r= oca;
      if (val)
	*val&= 2;
      break;
    case cfg_ddca	: r= ddca;
      if (val)
	{
	  *val&= 2;
	  u8_t i= cra->get() & 0xdf;
	  if (*val) i|= 0x20;
	  cra->set(i);
	}
      else
	r->set((cra->get() & 0x20)?2:0);
      break;
    case cfg_inca	: r= inca;
      if (val)
	*val&= 3;
      break;
    case cfg_ocb	: r= ocb;
      if (val)
	*val&= 2;
      break;
    case cfg_ddcb	: r= ddcb;
      if (val)
	{
	  *val&= 2;
	  u8_t i= crb->get() & 0xdf;
	  if (*val) i|= 0x20;
	  crb->set(i);
	}
      else
	r->set((crb->get() & 0x20)?2:0);
      break;
    case cfg_incb	: r= incb;
      if (val)
	*val&= 3;
      break;
    }
  if (r)
    {
      if (val)
	r->set(*val);
      v= r->get();
      cell->set(v);
    }
  v= cell->get();
  return v;
}

int
cl_port::ca1()
{
  return inca->get() & 1;
}

int
cl_port::ca2(void)
{
  u8_t ca= cra->get();
  if (ca & 0x20)
    {
      // out
      return (oca->get() & 2)?1:0;
    }
  // input
  return (inca->get() & 2)?1:0;
  return 0;
}

int
cl_port::cb1()
{
  return incb->get() & 1;
}

int
cl_port::cb2(void)
{
  u8_t cb= crb->get();
  if (cb & 0x20)
    {
      // out
      return (ocb->get() & 2)?1:0;
    }
  // input
  return (incb->get() & 2)?1:0;
  return 0;
}

int
cl_port::tick(int cycles)
{
  u8_t ca= cra->get();
  u8_t cb= crb->get();
  if (ca & 1)
    {
      int a1= ca1();
      if (( (ca & 2) && !prev_ca1 &&  a1) ||
	  (!(ca & 2) &&  prev_ca1 && !a1)
	  )
	{
	  cra->write(ca | 0x80);
	}
    }
  if (prev_ca1 != ca1()) prev_ca1= ca1();
  if (cb & 1)
    {
      int b1= cb1();
      if (( (cb & 2) && !prev_cb1 &&  b1) ||
	  (!(cb & 2) &&  prev_cb1 && !b1)
	  )
	{
	  crb->write(cb | 0x80);
	}
    }
  if (prev_cb1 != cb1()) prev_cb1= cb1();
  return 0;
}

void
cl_port::set_cmd(class cl_cmdline *cmdline, class cl_console_base *con)
{
  class cl_cmd_arg *params[2]= {
    cmdline->param(0),
    cmdline->param(1)
  };

  if (cmdline->syntax_match(uc, NUMBER))
    {
      int i;
      t_addr a= params[0]->value.number;
      if (!uc->rom->valid_address(a))
	{
	  con->dd_printf("Address must be between 0x%x and 0x%x\n",
			 AU(uc->rom->lowest_valid_address()),
			 AU(uc->rom->highest_valid_address()));
	  return;
	}
      for (i= 0; i < 3; i++)
	unregister_cell(rs[i]);
      base= a;
      init();
    }
  else
    con->dd_printf("set hardware port[%d] address\n", id);
}

void
cl_port::print_info(class cl_console_base *con)
{
  u8_t ca= cra->get();
  u8_t cb= crb->get();
  con->dd_printf("%s[%d] at 0x%06x %s\n", id_string, id, base, on?"on ":"off");
  con->dd_printf("0x%04x ", base+0);
  if (cra->get() & 4)
    con->dd_printf(" ORA 0x%02x", ora->get());
  else
    con->dd_printf("DDRA 0x%02x", ddra->get());
  con->dd_printf("\n");
  con->dd_printf("0x%04x ", base+1);
  con->dd_printf(" CRA 0x%02x", ca);
  con->dd_printf("   IRQA1 %d", (ca&0x80)?1:0);
  con->dd_printf("   EnA1 %d", (ca&0x01)?1:0);
  con->dd_printf("   EdgA1 %d", (ca&0x02)?1:0);
  con->dd_printf("   CA1 %d", ca1());
  con->dd_printf("\n                ");
  con->dd_printf("   IRQA2 %d", (ca&0x40)?1:0);
  con->dd_printf("   EnA2 %d", ((ca&0x28)==0x08)?1:0);
  con->dd_printf("   EdgA2 %d", (ca&0x10)?1:0);
  con->dd_printf("   CA2 %d", ca2());
  con->dd_printf("\n                ");
  con->dd_printf("   DirA2 %s", (ca&0x20)?"Out":"In ");
  con->dd_printf(" ModA2 ");
       if ((ca&0x38) == 0x30) con->dd_printf("Output 0               ");
  else if ((ca&0x38) == 0x38) con->dd_printf("Output 1               ");
  else if ((ca&0x38) == 0x20) con->dd_printf("Read strobe, A1 restore");
  else if ((ca&0x08) == 0x28) con->dd_printf("Read strobe,  E restore");
  else                        con->dd_printf("Input                  ");
  con->dd_printf("\n");
  
  con->dd_printf("0x%04x ", base+2);
  if (crb->get() & 4)
    con->dd_printf(" ORB 0x%02x", orb->get());
  else
    con->dd_printf("DDRB 0x%02x", ddrb->get());
  con->dd_printf("\n");
  con->dd_printf("0x%04x ", base+3);
  con->dd_printf(" CRB 0x%02x", cb);
  con->dd_printf("   IRQB1 %d", (cb&0x80)?1:0);
  con->dd_printf("   EnB1 %d", (cb&0x01)?1:0);
  con->dd_printf("   EdgB1 %d", (cb&0x02)?1:0);
  con->dd_printf("   CB1 %d", cb1());
  con->dd_printf("\n                ");
  con->dd_printf("   IRQB2 %d", (cb&0x40)?1:0);
  con->dd_printf("   EnB2 %d", ((cb&0x28)==0x08)?1:0);
  con->dd_printf("   EdgB2 %d", (cb&0x10)?1:0);
  con->dd_printf("   CB2 %d", cb2());
  con->dd_printf("\n                ");
  con->dd_printf("   DirB2 %s", (ca&0x20)?"Out":"In ");
  con->dd_printf(" ModB2 ");
       if ((cb&0x38) == 0x30) con->dd_printf("Output 0                ");
  else if ((cb&0x38) == 0x38) con->dd_printf("Output 1                ");
  else if ((cb&0x08) == 0x20) con->dd_printf("Write strobe, A1 restore");
  else if ((cb&0x08) == 0x28) con->dd_printf("Write strobe,  E restore");
  else                        con->dd_printf("Input                   ");
  con->dd_printf("\n");

  //print_cfg_info(con);
}

/* End of m6809.src/port.cc */
