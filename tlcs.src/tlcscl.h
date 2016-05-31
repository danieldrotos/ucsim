/*@1@*/

#ifndef TLCSCL_HEADER
#define TLCSCL_HEADER

// sim.src
#include "uccl.h"
#include "memcl.h"


/*
 * Base type of TLCS microcontrollers
 */

class cl_tlcs: public cl_uc
{
 public:
  class cl_address_space *ram;
  class cl_address_space *rom;
 public:
  cl_tlcs(class cl_sim *asim);
  virtual int init(void);
  virtual char *id_string(void);

  //virtual t_addr get_mem_size(enum mem_class type);
  //virtual int get_mem_width(enum mem_class type);
  virtual void mk_hw_elements(void);
  virtual void make_memories(void);

  //virtual struct dis_entry *dis_tbl(void);
  //virtual struct name_entry *sfr_tbl(void);
  //virtual struct name_entry *bit_tbl(void);
  //virtual const char *disass(t_addr addr, const char *sep);
  //virtual void print_regs(class cl_console_base *con);

  //virtual int exec_inst(void);
};


#endif

/* End of tlcs.src/tlcscl.h */
