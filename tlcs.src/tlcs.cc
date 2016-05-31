/*@1@*/

#include "ddconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "i_string.h"

// prj
#include "pobjcl.h"

// sim
#include "simcl.h"
#include "memcl.h"

// local
#include "tlcscl.h"
#include "glob.h"


/*
 * Base type of TLCS microcontrollers
 */

cl_tlcs::cl_tlcs(class cl_sim *asim):
  cl_uc(asim)
{
  //type= CPU_TLCS;
  //sleep_executed= 0;
}

int
cl_tlcs::init(void)
{
  cl_uc::init(); /* Memories now exist */
  ram= address_space(MEM_IRAM_ID);
  rom= address_space(MEM_ROM_ID);
  return(0);
}

char *
cl_tlcs::id_string(void)
{
  return((char*)"unspecified TLCS");
}


void
cl_tlcs::mk_hw_elements(void)
{
  //class cl_base *o;
  //hws->add(o= new cl_port(this));
  //o->init();
}


void
cl_tlcs::make_memories(void)
{
  class cl_address_space *as;

  rom= as= new cl_address_space(MEM_ROM_ID, 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);
  ram= as= new cl_address_space(MEM_IRAM_ID, 0, 0x10000, 8);
  as->init();
  address_spaces->add(as);

  class cl_address_decoder *ad;
  class cl_memory_chip *chip;

  chip= new cl_memory_chip("rom_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= rom/*address_space(MEM_ROM_ID)*/,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);

  chip= new cl_memory_chip("iram_chip", 0x10000, 8);
  chip->init();
  memchips->add(chip);
  ad= new cl_address_decoder(as= ram/*address_space(MEM_IRAM_ID)*/,
			     chip, 0, 0xffff, 0);
  ad->init();
  as->decoders->add(ad);
  ad->activate(0);
}


/* End of tlcs.src/tlcs.cc */
