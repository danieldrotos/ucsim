/*
 * Simulator of microcontrollers (glob.cc)
 *
 * Copyright (C) @@S@@,@@Y@@ Drotos Daniel, Talker Bt.
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

#include "glob.h"

struct cpu_entry cpus_8085[]=
  {
    {"I8080"	, CPU_I8080, 0		, "I8080", ""},
    {"8080"	, CPU_I8080, 0		, "I8080", ""},
    {"80"	, CPU_I8080, 0		, "I8080", ""},
    {"I8085"	, CPU_I8085, 0		, "I8085", ""},
    {"8085"	, CPU_I8085, 0		, "I8085", ""},
    {"85"	, CPU_I8085, 0		, "I8085", ""},

    {NULL, CPU_NONE, 0, "", ""}
  };

/* End of i8085.src/glob.cc */
