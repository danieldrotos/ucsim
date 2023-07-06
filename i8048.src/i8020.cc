/*
 * Simulator of microcontrollers (i8020.cc)
 *
 * Copyright (C) 2022 Drotos Daniel, Talker Bt.
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

#include <ctype.h>

#include "utils.h"

#include "glob.h"

#include "i8020cl.h"


/*
 * Flags
 */

t_mem
cl_flag20_op::write(t_mem val)
{
  val|= 0x08;
  return val;
}


/*
 * CPU
 */

cl_i8020::cl_i8020(class cl_sim *asim):
  cl_uc(asim)
{
  PCmask= 0xfff;
}

int
cl_i8020::init(void)
{
  class cl_memory_operator *o;

  o= new cl_pc_op(&cPC);
  o->init();
  cPC.append_operator(o);

  cflagF1.init();
  cflagF1.decode(&flagF1);
  o= new cl_bool_op(&cflagF1);
  o->init();
  cflagF1.append_operator(o);
  cflagF1.set_mask(1);

  cmb.init();
  cmb.decode(&mb);
  o= new cl_bool_op(&cmb);
  o->init();
  cmb.append_operator(o);
  cmb.set_mask(1);

  cl_uc::init();

  mk_cvar(&cflagF1, "F1", "CPU flag F1");
  mk_cvar(&cmb, "mb", "CPU code bank selector");
  mk_cvar(&cmb, "A11", "CPU code bank selector");
  
  //reset();
  return 0;
}

const char *
cl_i8020::id_string(void)
{
  return "i8020";
}

void
cl_i8020::set_PC(t_addr addr)
{
  // do not change A11
  PC&= 0x7ff;
  addr&= 0x7ff;
  PC|= addr;
}

void
cl_i8020::make_memories(void)
{
  class cl_memory_operator *o;
  make_address_spaces();
  // setup psw
  cpsw= (cl_cell8*)aspsw->get_cell(0);
  cpsw->decode(&psw);
  o= new cl_flag20_op(cpsw);
  o->init();
  o->set_name("MCS48 flag operator");
  cpsw->append_operator(o);
  reg_cell_var(cpsw, &psw, "psw", "CPU register PSW");
  // do others
  make_chips();
  decode_regs();
  decode_rom();
  decode_iram();
}

void
cl_i8020::make_address_spaces(void)
{
  rom= new cl_address_space("rom", 0, 0x1000, 8);
  rom->init();
  address_spaces->add(rom);
  
  iram= new cl_address_space("iram", 0, 0x100, 8);
  iram->init();
  address_spaces->add(iram);

  regs= new cl_address_space("regs", 0, 8, 8);
  regs->init();
  address_spaces->add(regs);

  aspsw= new cl_address_space("aspsw", 0, 1, 8);
  aspsw->init();
  //address_spaces->add(aspsw);
}

void
cl_i8020::make_chips(void)
{
  rom_chip= new cl_chip8("rom_chip", 0x1000, 8, 0xff);
  rom_chip->init();
  memchips->add(rom_chip);
  
  iram_chip= new cl_chip8("iram_chip", 0x100, 8);
  iram_chip->init();
  memchips->add(iram_chip);
}

void
cl_i8020::decode_rom(void)
{
  class cl_address_decoder *ad;
  ad= new cl_address_decoder(rom, rom_chip, 0, 0xfff, 0);
  ad->init();
  ad->set_name("def_rom_decoder");
  rom->decoders->add(ad);
  ad->activate(0);
}

void
cl_i8020::decode_regs(void)
{
  int i;
  cl_banker *b= new cl_banker(aspsw, 0, flagBS, //0,
			      regs, 0, 7);
  b->init();
  b->set_name("def_regs_banker");
  regs->decoders->add(b);
  b->add_bank(0, memory("iram_chip"), 0);
  b->add_bank(1, memory("iram_chip"), 24);
  cpsw->write(0);
  for (i= 0; i < 8; i++)
    R[i]= regs->get_cell(i);
}

void
cl_i8020::decode_iram(void)
{
  class cl_address_decoder *ad;
  
  ad= new cl_address_decoder(iram, iram_chip, 0, 0xff, 0);
  ad->init();
  ad->set_name("def_iram_decoder");
  iram->decoders->add(ad);
  ad->activate(0);
}

void
cl_i8020::print_regs(class cl_console_base *con)
{
  int start, stop;
  t_mem data;
  u16_t dp;
  // show regs
  start= (psw & flagBS)?24:0;
  con->dd_color("answer");
  con->dd_printf("        R0 R1 R2 R3 R4 R5 R6 R7    PSW= CAFB-SSS    ACC= ");
  con->dd_color("dump_number");
  con->dd_printf("0x%02x %+3d %c", ACC, ACC, (isprint(ACC)?ACC:'?'));
  con->dd_printf("\n");
  con->dd_cprintf("dump_address", "   0x%02x", start);
  for (t_addr i= 0; i < 8; i++)
    con->dd_cprintf("dump_number", " %02x", iram->get(start + i));
  con->dd_cprintf("dump_number", "    0x%02x ", psw);
  con->dd_color("dump_number");
  con->print_bin(psw, 8);
  con->dd_printf("    A11=%d F1=%d", mb, flagF1);
  con->dd_printf("\n");
  // show indirectly addressed IRAM and some basic regs
  start= R[0]->get();
  stop= start+7;
  con->dd_color("answer");
  con->dd_printf("R0=");
  iram->dump(0, start, stop, 8, con);
  start= R[1]->get();
  stop= start+7;
  con->dd_color("answer");
  con->dd_printf("R1=");
  iram->dump(0, start, stop, 8, con);
  /*
  data= iram->get(iram->get(start));
  con->dd_printf("@R0 %02x %c", data, isprint(data) ? data : '.');
  
  con->dd_printf("  ACC= 0x%02x %3d %c\n", ACC, ACC,
              isprint(ACC)?(ACC):'.');
  data= iram->get(iram->get(start+1));
  con->dd_printf("@R1 %02x %c", data, isprint(data) ? data : '.');
  data= psw;
  con->dd_printf("  PSW= 0x%02x CY=%c AC=%c F0=%c BS=%c\n", data,
		 (data&flagC)?'1':'0', (data&flagA)?'1':'0',
		 (data&flagF0)?'1':'0', (data&flagBS)?'1':'0');
  */
  print_disass(PC, con);
}

void
cl_i8020::reset(void)
{
  // 1) PC=0
  cPC.W(0);
  // 2) SP=0, 3) regbank=0
  cpsw->W(0);
  // 4) membank=0
  cmb.W(0);
  // 5) BUS=> HiZ
  // 6) Port1, Port2: input mode
  // 7) disbale irq
  // 8) stop timer
  // 9) clear timer flag
  // 10) Clear F0, F1
  cflagF1.W(0);
  // 11) disable clock output from T0
}

int
cl_i8020::exec_inst(void)
{
  return exec_inst_uctab();
}


/* End of i8048.src/i8020.cc */
