#ifndef MACRO_H_
#define MACRO_H_

/*
	Copyright (C) 2017 Stephen M. Cameron
	Author: Stephen M. Cameron

	This file is part of smcameron-nanogenmo-2017.

	smcameron-nanogenmo-2017 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	smcameron-nanogenmo-2017 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with smcameron-nanogenmo-2017; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

struct macro {
	char *name;
	int nalts;
	char **alt;
};

struct macro_set_entry {
        int nmacros;
        struct macro *m;
};

char *expand_macros_by_type(char *input, int type);
char *expand_macros(char *input);

void init_macros(void);
void add_macro_set(char *setname);
void add_macro(char *setname, char *name, char *alt);
void remove_macro(char *setname, char *name, char *alt);

#endif
