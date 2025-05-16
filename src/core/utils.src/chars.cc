/*
 * Simulator of microcontrollers (chars.cc)
 *
 * Copyright (C) 1997 Drotos Daniel
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

#include "charscl.h"


chars::chars(void)
{
  chars_string= 0;
  chars_length= 0;
  dynamic= false;
  pars_pos= 0;
}

chars::chars(char *s)
{
  chars_string= 0;
  chars_length= 0;
  allocate_string(s);
}

chars::chars(const char *s)
{
  if ((chars_string= const_cast<char *>(s)) != NULL)
    chars_length= strlen(s);
  else
    chars_length= 0;
  dynamic= false;
  pars_pos= 0;
}
chars::chars(const chars &cs)
{
  chars_string= 0;
  chars_length= 0;
  allocate_string(cs);
}

chars::chars(const char *, const char *fmt, ...)
{
  va_list ap;
  char n[1000];

  va_start(ap, fmt);
  vsnprintf(n, 999, fmt, ap);
  va_end(ap);

  chars_string= strdup(n);
  chars_length= strlen(n);
  dynamic= true;
  pars_pos= 0;
}

chars::~chars(void)
{
  deallocate_string();
}


void
chars::allocate_string(const char *s)
{
  char *n= NULL;
  int l= 0;
  bool d= false;
  
  if (s)
    {
      l= strlen(s);
      n= (char*)malloc(l+1);
      strcpy(n, s);
      d= true;
    }
  deallocate_string();
  chars_length= l;
  chars_string= n;
  dynamic= d;
  pars_pos= 0;
}

void
chars::deallocate_string(void)
{
  if (chars_string)
    if (dynamic)
      free(chars_string);
  chars_string= 0;
  chars_length= 0;
  dynamic= 0;
}


/*
 * Content of the object
 */

char
chars::c(int idx) const
{
  if (!chars_string)
    return 0;
  if (idx>=chars_length)
    return 0;
  return chars_string[idx];
}


/*
 * Create content in the object
 */

chars &
chars::append(const char *s)
{
  if (!s)
    return(*this);

  char *temp= (char*)malloc(chars_length + strlen(s) + 1);
  if (chars_string)
    {
      strcpy(temp, chars_string);
      if (dynamic)
	free(chars_string);
    }
  else
    temp[0]= '\0';
  strcat(temp, s);
  chars_string= temp;
  chars_length+= strlen(s);
  dynamic= true;
  
  return *this;
}

chars &
chars::append(char c)
{
  if (!c)
    return(*this);

  char *temp= (char*)malloc(chars_length + 1 + 1);
  if (chars_string)
    {
      strcpy(temp, chars_string);
      if (dynamic)
	free(chars_string);
    }
  else
    temp[0]= '\0';
  char b[2];
  b[0]= c;
  b[1]= 0;
  strcat(temp, b);
  chars_string= temp;
  chars_length+= 1;
  dynamic= true;

  return *this;
}

chars &
chars::appendf(const char *format, ...)
{
  va_list ap;
  char n[1000];
  
  va_start(ap, format);
  vsnprintf(n, 999, format, ap);
  va_end(ap);

  char *temp= (char*)malloc(chars_length + strlen(n) + 1);
  if (chars_string)
    {
      strcpy(temp, chars_string);
      if (dynamic)
	free(chars_string);
    }
  else
    temp[0]= '\0';
  strcat(temp, n);
  chars_string= temp;
  chars_length+= strlen(n);
  dynamic= true;
  
  return *this;
}

chars &
chars::appendn(const char *src, int n)
{
  char *temp= (char*)malloc(chars_length + n + 1);
  if (chars_string)
    {
      strcpy(temp, chars_string);
      if (dynamic)
	free(chars_string);
    }
  else
    temp[0]= 0;
  int s= 0;
  while (src[s] && (s<n))
    temp[chars_length++]= src[s++];
  temp[chars_length]= '\0';
  chars_string= temp;
  dynamic= true;
  return *this;
}

chars &
chars::format(const char *format, ...)
{
  deallocate_string();

  va_list ap;
  char n[1000];
  
  va_start(ap, format);
  vsnprintf(n, 999, format, ap);
  va_end(ap);

  char *temp= (char*)malloc(chars_length + strlen(n) + 1);
  if (chars_string)
    {
      strcpy(temp, chars_string);
      if (dynamic)
	free(chars_string);
    }
  else
    temp[0]= '\0';
  strcat(temp, n);
  chars_string= temp;
  chars_length+= strlen(n);
  dynamic= true;
  
  return *this;
}


/*
 * Get properies of the object
 */


/*
 * Change content of the object
 */

void
chars::uppercase(void)
{
  if (!dynamic)
    allocate_string(chars_string);

  for (int i= 0; i < chars_length; i++)
    chars_string[i]= toupper(chars_string[i]);
}

void
chars::lowercase(void)
{
  if (!dynamic)
    allocate_string(chars_string);

  for (int i= 0; i < chars_length; i++)
    chars_string[i]= tolower(chars_string[i]);
}

void
chars::replace(const char *any_in_set, char with)
{
  if (!dynamic)
    allocate_string(chars_string);

  for (int i= 0; i < chars_length; i++)
    if (strchr(any_in_set, chars_string[i]))
      chars_string[i] = with;
}

void
chars::keep(int start, int maxlen)
{
  if (!chars_string)
    return ;

  char *s= (char*)malloc(maxlen+1);
  int i, l;
  for (i= start, l= 0; i<chars_length && chars_string[i] && l<maxlen; i++, l++)
    s[l]= chars_string[i];
  s[l]= 0;
  deallocate_string();
  chars_string= s;
  chars_length= l;
  dynamic= true;
}

void
chars::ltrim(void)
{
  char *p= chars_string;
  if (empty())
    return;
  while (*p && isspace(*p))
    p++;
  allocate_string(p);
}

void
chars::rtrim(void)
{
  int i;
  if (empty())
    return;
  i= chars_length-1;
  while (i>=0)
    {
      if (isspace(chars_string[i]))
	chars_string[i]= 0;
      else
	break;
      i--;
    }
}

void
chars::lrip(const char *cset)
{
  int skip;
  if (empty())
    return;
  if (!cset || !*cset)
    return;
  skip= strspn(chars_string, cset);
  if (skip > 0)
    allocate_string(chars_string+skip);
}

void
chars::rrip(const char *cset)
{
  if (empty())
    return;
  if (!cset || !*cset)
    return;
  int i= chars_length-1;
  while (i>=0)
    {
      char c= chars_string[i];
      if (strchr(cset, c) != NULL)
	{
	  chars_string[i]= 0;
	  chars_length--;
	}
      else
	break;
      i--;
    }
}

void
chars::rrip(int nuof_chars)
{
  if (empty()) return;
  if (nuof_chars < 1) return;
  int i= chars_length-1;
  while ((i>=0) && nuof_chars)
    {
      chars_string[i]= 0;
      i--;
      nuof_chars--;
      chars_length--;
    }
}


/*
 * Parsing content of the object
 */

chars
chars::token(const char *delims) const
{
  chars c= (char*)NULL;

  if (!delims || !*delims)
    return c;
  if (pars_pos >= chars_length)
    return c;
  if (chars_length < 1)
    return c;

  int l;
  // skip initial delims first;
  l= strspn(&chars_string[pars_pos], delims);
  pars_pos+= l;
  if (pars_pos >= chars_length)
    return c;
  // skip chars not in delims: search token end
  l= strcspn(&chars_string[pars_pos], delims);
  if (l > 0)
    {
      // found
      int i;
      for (i= pars_pos; i < pars_pos+l; i++)
	c+= chars_string[i];
      pars_pos= i;
      // skip delims at end
      l= strspn(&chars_string[pars_pos], delims);
      pars_pos+= l;
      return c;
    }
  // not found more
  return c;
}

chars
chars::substr(int start, int len)
{
  chars c= (char*)NULL;
  if (empty() || (start >= chars_length))
    return c;
  int i, l= len+start;
  for (i= start; chars_string[i] && (i < l); i++)
    c+= chars_string[i];
  return c;
}

unsigned int
chars::htoi(void) const
{
  unsigned int v= 0;
  int i, x;
  if (!chars_string)
    return 0;
  for (i= 0; chars_string[i]; i++)
    {
      char c= toupper(chars_string[i]);
      if ((c>='0') && (c<='9'))
	x= c-'0';
      else if ((c>='A') && (c<='F'))
	x= 10+c-'A';
      else
	x= 0;
      v<<= 4;
      v|= x;
    }
  return v;
}

unsigned long long int
chars::htoll(void) const
{
  unsigned long long int v= 0;
  int i, x;
  if (!chars_string)
    return 0;
  for (i= 0; chars_string[i]; i++)
    {
      char c= toupper(chars_string[i]);
      if ((c>='0') && (c<='9'))
	x= c-'0';
      else if ((c>='A') && (c<='F'))
	x= 10+c-'A';
      else
	return v;//x= 0;
      v<<= 4;
      v|= x;
    }
  return v;
}

long int
chars::lint(void) const
{
  return lint(10);
}

long int
chars::lint(int base) const
{
  if (base < 2) base= 0;
  if (base > 36) base= 36;
  if (empty()) return 0;
  long int l= strtol(chars_string, 0, base);
  return l;
}


/*
 * Search text/char in the object
 */

bool
chars::starts_with(const char *x) const
{
  if (empty() ||
      !x ||
      !*x)
    return false;
  if (strstr(chars_string, x) == chars_string)
    return true;
  return false;
}

bool
chars::starts_with(chars x) const
{
  if (empty() ||
      x.empty())
    return false;
  if (strstr(chars_string, x.c_str()) == chars_string)
    return true;
  return false;
}

bool
chars::contains(const char *x) const
{
  if (empty() ||
      !x ||
      !*x)
    return false;
  if (strstr(chars_string, x) != NULL)
    return true;
  return false;
}

bool
chars::contains(chars x) const
{
  if (empty() ||
      x.empty())
    return false;
  if (strstr(chars_string, x.c_str()) != NULL)
    return true;
  return false;
}

bool
chars::icontains(const char *x) const
{
  if (empty() ||
      !x ||
      !*x)
    return false;
  chars s1= chars_string;
  chars s2= x;
  s1.uppercase();
  s2.uppercase();
  return s1.contains(s2);
}

bool
chars::icontains(chars x) const
{
  if (empty() ||
      x.empty())
    return false;
  chars s1= chars_string;
  chars s2= x;
  s1.uppercase();
  s2.uppercase();
  return s1.contains(s2);
}

int
chars::pos(char c) const
{
  if (empty())
    return -1;
  char *p= strchr(chars_string, c);
  if (p == NULL)
    return -1;
  return p-chars_string;
}

int
chars::pos(chars x) const
{
  if (empty() || x.empty())
    return -1;
  const char *p= strstr(chars_string, x.c_str());
  if (p == NULL)
    return -1;
  return p-chars_string;
}

int
chars::ipos(chars x) const
{
  if (empty() || x.empty())
    return -1;
  chars h= c_str();
  chars n= x;
  h.uppercase();
  n.uppercase();
  const char *s= h.c_str();
  const char *p= strstr(s, x.c_str());
  if (p == NULL)
    return -1;
  return p-s;
}


// Assignment operators
chars &
chars::operator=(const char *s)
{
  allocate_string(s);
  return(*this);
}

chars &
chars::operator=(const chars &cs)
{
  if (this != &cs)
    allocate_string(cs.chars_string);
  return(*this);
}


// Arithmetic operators

chars
chars::operator+(char c)
{
  char b[2];
  b[0]= c;
  b[1]= 0;
  chars temp(chars_string);
  return temp.append(b);
}

chars
chars::operator+(const char *s)
{
  chars temp(chars_string);
  return(temp.append(s));
}

chars
operator+(char c, const chars &cs)
{
  char b[2];
  b[0]= c;
  b[1]= 0;
  chars temp(b);
  return(temp.append(cs));
}


// Boolean operators

bool
chars::equal(const char *s) const
{
  if ((chars_string &&
       !s) ||
      (!chars_string &&
       s))
    return(0);
  if (!chars_string &&
      !s)
    return(1);
  return(strcmp(chars_string, s) == 0);
}

bool
chars::iequal(const char *s) const
{
  if ((chars_string &&
       !s) ||
      (!chars_string &&
       s))
    return(0);
  if (!chars_string &&
      !s)
    return(1);
  int i=0, j=0;
  while (chars_string[i] && s[j])
    if (toupper(chars_string[i++]) != toupper(s[j++]))
      return false;
  return !chars_string[i] && !s[j];
}

bool
chars::operator==(const char *s) const
{
  return(equal(s));
}

bool
chars::operator!=(const char *s) const
{
  return(!equal(s));
}


/* End of utils.src/chars.cc */
