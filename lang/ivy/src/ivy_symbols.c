/* Symbol (interned string) management

   Copyright (C) 1993 Joseph H. Allen

This file is part of IVY

IVY is free software; you can redistribute it and/or modify it under the 
terms of the GNU General Public License as published by the Free Software 
Foundation; either version 1, or (at your option) any later version.  

IVY is distributed in the hope that it will be useful, but WITHOUT ANY 
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
details.  

IVY; see the file COPYING.  If not, write to the Free Software Foundation, 
675 Mass Ave, Cambridge, MA 02139, USA.  */

#include <string.h>
#include "hash.h"
#include "ivy_symbols.h"

Hash_table *symbol_table;

int symbol_count;

char *symbol_add(const char *name)
{
	char *s;
	unsigned hval;
	if (!symbol_table)
		symbol_table = htmk(1024);
	hval = hash(name);
	s = (char *)htfindhval(symbol_table, name, hval);
	if (!s) {
		s = strdup(name);
		htaddhval(symbol_table, s, hval, s);
		++symbol_count;
	}
	return s;
}

char *symbol_noadd(const char *name)
{
	unsigned hval;
	if (!symbol_table)
		symbol_table = htmk(1024);
	hval = hash(name);
  	return (char *)htfindhval(symbol_table, name, hval);
}