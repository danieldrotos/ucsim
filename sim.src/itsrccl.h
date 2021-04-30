/*
 * Simulator of microcontrollers (sim.src/itsrccl.h)
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

#ifndef SIM_ITSRCCL_HEADER
#define SIM_ITSRCCL_HEADER

#include "pobjcl.h"
#include "stypes.h"

#include "uccl.h"
#include "memcl.h"
#include "itsrccl.h"


/*
 * Represents source of interrupt
 */

class cl_it_src: public /*cl_base*/cl_hw
{
 private:
  class cl_uc *uc;
 protected:
  class cl_memory_cell *ie_cell;
  class cl_memory_cell *src_cell;
public:
  int poll_priority;
  int    nuof;	   // Number of IT to check priority
  t_mem  ie_mask;  // Mask in IE register
  t_mem  ie_value; // Enabled when masked cell equals to this
  t_mem  src_mask; // Mask of source bit in src_reg
  t_mem  src_value;// Requested when masked cell equals to this
  t_addr addr;     // Address of service routine
  bool   clr_bit;  // Request bit must be cleared when IT accepted
  bool   active;   // Acceptance can be disabled
  bool   indirect; // address comes from a vector table from `addr'
  
  cl_it_src(cl_uc  *Iuc,
	    int    Inuof,
	    class  cl_memory_cell *Iie_cell,
	    t_mem  Iie_mask,
	    class  cl_memory_cell *Isrc_cell,
	    t_mem  Isrc_mask,
	    t_addr Iaddr,
	    bool   Iclr_bit,
	    bool   Iindirect,
	    const  char *Iname,
	    int    apoll_priority);
  virtual ~cl_it_src(void);
  virtual int init(void);
  virtual void set_ie_value(t_mem iv) { ie_value= iv; }
  virtual void set_src_value(t_mem sv) { src_value= sv; }
  virtual bool is_nmi(void) { return false; }
  
          bool is_active(void);
  virtual void set_active_status(bool Aactive);
  virtual void activate(void);
  virtual void deactivate(void);

  virtual bool enabled(void);
  virtual bool pending(void);
  virtual void clear(void);

  virtual void write(class cl_memory_cell *cell, t_mem *val);
  virtual t_mem read(class cl_memory_cell *cell);
};

/* Somehow specialized base which is used by several simulators */

enum irq_nr {
  irq_none= 0,
  irq_nmi= 1,
  irq_firq= 2,
  irq_irq= 3
};

class cl_m6xxx_src: public cl_it_src
{
public:
  u8_t Evalue;
  u8_t IFvalue;
  enum irq_nr pass_to;
public:
  cl_m6xxx_src(cl_uc  *Iuc,
	       int    Inuof,
	       class  cl_memory_cell *Iie_cell,
	       t_mem  Iie_mask,
	       class  cl_memory_cell *Isrc_cell,
	       t_mem  Isrc_mask,
	       t_addr Iaddr,
	       const  char *Iname,
	       int    apoll_priority,
	       u8_t   aEvalue,
	       u8_t   aIFvalue,
	       enum irq_nr Ipass_to):
    cl_it_src(Iuc, Inuof, Iie_cell, Iie_mask, Isrc_cell, Isrc_mask, Iaddr, false, true, Iname, apoll_priority)
  {
    Evalue= aEvalue;
    IFvalue= aIFvalue;
    pass_to= Ipass_to;
  }
  virtual bool is_nmi(void) { return false; }
  virtual void clear(void) { src_cell->write(0); }
  virtual class cl_m6xxx_src *get_parent(void) { return NULL; }
  virtual void set_pass_to(enum irq_nr value) { pass_to= value; }
  virtual void set_pass_to(t_mem value);
};


/* IRQ list */

class cl_irqs: public cl_sorted_list
{
public:
  cl_irqs(t_index alimit, t_index adelta);
  virtual const void *key_of(const void *item) const;
  virtual int compare(const void *key1, const void *key2);
};


/*
 * This class is used to follow levels of accepted interrupts
 * It used on a stack of active interrupt services (it_levels of cl_uc)
 */

class it_level: public cl_base
{
public:
  int level;
  uint addr;
  uint PC;
  class cl_it_src *source;
public:
  it_level(int alevel, uint aaddr, uint aPC, class cl_it_src *is);
};


#endif

/* End of itsrccl.h */
