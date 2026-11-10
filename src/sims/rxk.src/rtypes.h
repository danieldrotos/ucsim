/*
 * Simulator of microcontrollers (rtypes.h)
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

#ifndef RXK_RTYPES_HEADER
#define RXK_RTYPES_HEADER


#ifdef WORDS_BIGENDIAN
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NH;		\
			  u8_t NL;		\
			} r;			\
  } N
#define R32(N,N32,N16H,N16L,NHH,NHL,NLH,NLL)	\
  union						\
  {						\
  u32_t N32;					\
  struct {					\
    RP(r16h,N16H,NHH,NHL);			\
    RP(r16l,N16L,NLH,NLL);			\
  } r32;					\
  } N
#else
#define RP(N,N16,NH,NL) union			\
		      {				\
			u16_t N16;		\
			struct {		\
			  u8_t NL;		\
			  u8_t NH;		\
			} r;			\
  } N
#define R32(N,N32,N16H,N16L,NHH,NHL,NLH,NLL)	\
  union						\
  {						\
  u32_t N32;					\
  struct {					\
    RP(r16l,N16L,NLH,NLL);			\
    RP(r16h,N16H,NHH,NHL);			\
  } r32;					\
  } N
#endif


// hw message memories
enum rxk_hwmsg_t {
  rxkhw_perclk,		// Peripheral clock
  rxkhw_tastat,		// Timer A status
  rxkhw_tactrl,		// Timer A control
  rxkhw_ta1_in,		// Input of timer A1
  rxkhw_ta1_out,	// Output of timer A1
  rxkhw_ta2_out,	// Output of timer A2
  rxkhw_ta3_out,	// Output of timer A3
  rxkhw_ta4_out,	// Output of timer A4
  rxkhw_ta5_out,	// Output of timer A5
  rxkhw_ta6_out,	// Output of timer A6
  rxkhw_ta7_out,	// Output of timer A7
  rxkhw_ta8_out,	// Output of timer A8
  rxkhw_ta9_out,	// Output of timer A9
  rxkhw_ta10_out,	// Output of timer A10
  rxkhw_ta11_out,	// Output of timer A11
  rxkhw_ta12_out,	// Output of timer A12
  rxkhw_tbstat,		// Timer B status  ---- -XX-
  rxkhw_tbctrl,		// Timer B control ---- -XX-
  rxkhw_tb1_out,	// Output 1 of timer B
  rxkhw_tb2_out,	// Output 2 of timer B
  //rxkhw_tcstat,		// Timer C status  
  //rxkhw_tcctrl,		// Timer C control
  rxkhw_tc0_out,	// Output 0 of timer C
  rxkhw_tc1_out,	// Output 0 of timer C
  rxkhw_tc2_out,	// Output 0 of timer C
  rxkhw_tc3_out,	// Output 0 of timer C
};


#endif

/* End of rxk.src/rtypes.cc */
