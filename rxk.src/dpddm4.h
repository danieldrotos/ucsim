/*
 * Simulator of microcontrollers (dpddm4.h)
 *
 * Copyright (C) 2020,2021 Drotos Daniel, Talker Bt.
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

#ifndef DPDDM4_HEADER
#define DPDDM4_HEADER

#define LD_A_iIRA	instruction_dd_06
#define TEST_IR		instruction_dd_4c
#define LD_IRR_iHL	instruction_dd_1a
#define LD_IRR_iIXd	instruction_dd_ce
#define LD_IRR_iIYd	instruction_dd_de
#define LD_IRR_iSPn	instruction_dd_ee
#define LD_iHL_IRR	instruction_dd_1b
#define LD_iIXd_IRR	instruction_dd_cf
#define LD_iIYd_IRR	instruction_dd_df
#define LD_iSPn_IRR	instruction_dd_ef

#endif

/* End of rxk.src/dpddm4.h */
