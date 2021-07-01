#include "rxkcl.h"

#include "ddwrap.h"

int instruction_wrapper_dd_none(class cl_uc *uc, t_mem code) { return resINV_INST; }

int instruction_wrapper_dd_06(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_06(code); }
int instruction_wrapper_dd_09(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_09(code); }
int instruction_wrapper_dd_0a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0a(code); }
int instruction_wrapper_dd_0b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0b(code); }
int instruction_wrapper_dd_0c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0c(code); }
int instruction_wrapper_dd_0d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0d(code); }
int instruction_wrapper_dd_0e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0e(code); }
int instruction_wrapper_dd_0f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_0f(code); }

int instruction_wrapper_dd_19(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_19(code); }
int instruction_wrapper_dd_1a(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1a(code); }
int instruction_wrapper_dd_1b(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1b(code); }
int instruction_wrapper_dd_1c(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1c(code); }
int instruction_wrapper_dd_1d(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1d(code); }
int instruction_wrapper_dd_1e(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1e(code); }
int instruction_wrapper_dd_1f(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_dd_1f(code); }


void fill_dd_wrappers(instruction_wrapper_fn itab[])
{
  int i;
  for (i=0; i<256; i++)
    {
      itab[i]= instruction_wrapper_dd_none;
    }
  itab[0x06]= instruction_wrapper_dd_06;
  itab[0x09]= instruction_wrapper_dd_09;
  itab[0x0a]= instruction_wrapper_dd_0a;
  itab[0x0b]= instruction_wrapper_dd_0b;
  itab[0x0c]= instruction_wrapper_dd_0c;
  itab[0x0d]= instruction_wrapper_dd_0d;
  itab[0x0e]= instruction_wrapper_dd_0e;
  itab[0x0f]= instruction_wrapper_dd_0f;

  itab[0x19]= instruction_wrapper_dd_19;
  itab[0x1a]= instruction_wrapper_dd_1a;
  itab[0x1b]= instruction_wrapper_dd_1b;
  itab[0x1c]= instruction_wrapper_dd_1c;
  itab[0x1d]= instruction_wrapper_dd_1d;
  itab[0x1e]= instruction_wrapper_dd_1e;
  itab[0x1f]= instruction_wrapper_dd_1f;
}
