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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <ctype.h>

#include "macros.h"
#include "print.h"

#define MAXCHARS 10
struct character {
	char *firstname;
	char *middlename;
	char *lastname;
	char *title;
	char *third;
	char *Third;
	char *thirdp;
	int sex;
} cast[MAXCHARS];
int nchars = 0;

static void fixup_name_case(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (i > 0)
			s[i] = tolower(s[i]);
}

static void randomize(int seed)
{
	struct timeval tv;

	if (seed == 0) {
		gettimeofday(&tv, NULL);
		srand(tv.tv_usec);
	} else {
		srand(seed);
	}
}

static void generate_character(struct character *c)
{
	int i;

	c->lastname = expand_macros("[surname]");
	c->title = expand_macros("[character-title]");
	c->sex = rand() % 2;
	if (c->sex) {
		c->firstname = expand_macros("[male-firstname]"); 
		c->middlename = expand_macros("[male-firstname]"); 
		c->third = strdup("he");
		c->thirdp = strdup("his");
		c->Third = strdup("He");
	} else {
		c->firstname = expand_macros("[female-firstname]"); 
		c->middlename = expand_macros("[female-firstname]"); 
		c->third = strdup("she");
		c->thirdp = strdup("her");
		c->Third = strdup("She");
	}
	fixup_name_case(c->firstname);
	fixup_name_case(c->middlename);
	fixup_name_case(c->lastname);
}

static void print_character(struct character *c)
{
	printf("%s %s %s %s (%s)\n", c->title, c->firstname, c->middlename, c->lastname,
		c->sex ? "male" : "female");
}

static void generate_characters(void)
{
	int i;

	for (i = 0; i < MAXCHARS; i++)
		generate_character(&cast[i]);
	print("Cast of Characters\n\n");
	for (i = 0; i < MAXCHARS; i++)
		print_character(&cast[i]);
	printf("\n");
}

void introduction(void)
{
	print("Introduction\n\n");
	print("[intro]\n\n");
	char *setting = expand_macros_by_type("{setting}\n\n", '{');
	print(setting);
}

void ordinary_world(void)
{
	print("The Ordinary World\n\n");
	print("[the-ordinary-world]\n\n");
}

void call_to_adventure(void)
{
	print("The Call To Adventure\n\n");
}

void refusal_of_the_call(void)
{
	print("The Refusal of the Call\n\n");
}

void meeting_with_the_mentor(void)
{
	print("The Mentor\n\n");
}

void crossing_the_threshold(void)
{
	print("Crossing the Threshold\n\n");
}

void tests_allies_and_enemies(void)
{
	print("Tests, Allies, and Enemies\n\n");
}

void approach_the_challenge(void)
{
	print("The Approach of the Challenge\n\n");
}

void the_ordeal_and_confrontation(void)
{
	print("The Ordeal and Confrontation\n\n");
}

void the_reward_and_danger(void)
{
	print("Rewards and Dangers\n\n");
}

void the_road_back(void)
{
	print("The Road Back\n\n");
}

void the_final_conflict()
{
	print("The Final Conflict\n\n");
}

void the_return_with_the_elixir(void)
{
	print("The Return with the Elixir\n\n");
}

int main(int argc, char *argv[])
{
	init_macros();
	randomize(714882);
	generate_characters();
	add_macro("common_words", "Hero", cast[0].firstname);
	add_macro("common_words", "hero3", cast[0].third);
	add_macro("common_words", "hero3p", cast[0].thirdp);
	randomize(0);
	/* Let's try modelling after Joseph Campbell's Hero's Journey */
	introduction();
	ordinary_world();
	call_to_adventure();
	refusal_of_the_call();
	meeting_with_the_mentor();
	crossing_the_threshold();
	tests_allies_and_enemies();
	approach_the_challenge();
	the_ordeal_and_confrontation();
	the_reward_and_danger();
	the_road_back();
	the_final_conflict();
	the_return_with_the_elixir();
	return 0;
}
