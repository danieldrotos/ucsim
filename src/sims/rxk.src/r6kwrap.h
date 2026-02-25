/*
 * Simulator of microcontrollers (r6kwrap.h)
 *
 * Copyright (C) 2020 Drotos Daniel
 * 
 * To contact author send email to dr.dkdb@gmail.com
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

#ifndef R6KWRAP_HEADER
#define R6KWRAP_HEADER

#include "r6kcl.h"

#define WHEAD(X) int instruction_wrapper_ ##X ( class cl_uc *uc, t_mem code)
#define WDECL(X) extern WHEAD(X);
#define WCODE(X) WHEAD(X) \
  { return ((class cl_r6k *)uc)->instruction_ ##X (code); }

#ifdef WRAPPER_SOURCE
#define W(X) WCODE(X)
#else
#define W(X) WDECL(X)
#endif

W(6k11_43)
W(6k11_44)
W(6k11_4b)
W(6k11_53)
W(6k11_59)
W(6k11_69)
W(6k11_80)
W(6k11_88)
W(6k11_90)

W(6ked_86)
W(6ked_87)
W(6ked_96)
W(6ked_97)
W(6ked_a6)
W(6ked_b6)

#undef W
#undef WCODE
#undef WDECL
#undef WHEAD

#endif

/* End of rxk.src/r6kwrap.h */
