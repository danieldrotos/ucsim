/*@1@*/

#include "tlcscl.h"


// 08
int
cl_tlcs::ex_de_hl()
{
  uint16_t temp= reg.de;
  reg.de= reg.hl;
  reg.hl= temp;
  return resGO;
}


// 09
int
cl_tlcs::ex_af_alt_af()
{
  uint16_t temp= reg.af;
  reg.af= reg.alt_af;
  reg.alt_af= temp;
  return resGO;
}


// 0A
int
cl_tlcs::exx()
{
  uint16_t temp= reg.bc;
  reg.bc= reg.alt_bc;
  reg.alt_bc= temp;
  temp= reg.de;
  reg.de= reg.alt_de;
  reg.alt_de= temp;
  temp= reg.hl;
  reg.hl= reg.alt_hl;
  reg.alt_hl= temp;
  return resGO;
}


/* End of tlcs.src/block.cc */
