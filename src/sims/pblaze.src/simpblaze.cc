/*
 * Copyright (C) 2012-2013 Jiří Šimek
 * Copyright (C) 2013 Zbyněk Křivka <krivka@fit.vutbr.cz>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "simpblazecl.h"
#include "pblazecl.h"
#include "glob.h"

/**
 * Constructor
 */
cl_simpblaze::cl_simpblaze(class cl_app *the_app):
  cl_sim(the_app)
{}

/**
 * Creates new microcontroller instance
 */
class cl_uc *
cl_simpblaze::mk_controller(void)
{
  struct cpu_entry *ct;

  if ((ct= type_entry("")) == NULL)
    return NULL;

  return(new cl_pblaze(ct, this));
}

/* End of pblaze.src/simpblaze.cc */
