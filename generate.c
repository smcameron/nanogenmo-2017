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
#include <math.h>

#include "macros.h"
#include "print.h"

#define MAXCHARS 3
struct character {
	char *firstname;
	char *middlename;
	char *lastname;
	char *title;
	char *third;
	char *Third;
	char *thirdp;
	char *thirdpp;
	char *thirdself;
	int sex;
	int location;
	int introduced_yet;
} cast[MAXCHARS];
int nchars = 0;

/* Connections between locations */
struct connection {
	char *via; /* e.g. horseback, landspeeder, spaceship, walking, etc. */
	int from, to;
};

#define MAX_CONNECTIONS 100
#define MAX_LOCATIONS 100
#define MAX_SPACESHIPS 4
#define NLOCS_PER_PLANET 4
struct location {
	char *name;
	char *description;
	struct connection connection[MAX_CONNECTIONS];
	int nconnections;
	float x, y, z; /* location used for calculating distances/proximity */
	int planet; /* what planet this location is on */
#define LOCATION_TYPE_SPACESHIP 0
#define LOCATION_TYPE_PLANETARY 1
	int type;
} location[MAX_LOCATIONS];
int nlocations = 0;

/* These planets are very shallow, just groupings to associate locations */
#define MAX_PLANETS 5
#define MIN_PLANET_SEPARATION 3000.0
struct planet {
	char *name;
	float x, y, z;
} planet[MAX_PLANETS];
int nplanets;

static void generate_planets(void)
{
	int i, j, too_close;
	float dist, x, y, z;
	char name[100];

	nplanets = 0;
	for (i = 0; i < MAX_PLANETS; i++) {
		do {
			x = 100000.0 * ((float) rand() / (float) RAND_MAX);
			y = 100000.0 * ((float) rand() / (float) RAND_MAX);
			z = 100000.0 * ((float) rand() / (float) RAND_MAX);
			too_close = 0;
			for (j = 0; j < nplanets; j++) {
				float dx, dy, dz;
				dx = x - planet[j].x;
				dy = y - planet[j].y;
				dz = z - planet[j].z;
				dist = sqrt(dx * dx + dy * dy + dz * dz);
				if (dist < MIN_PLANET_SEPARATION) {
					too_close = 1;
					break;
				}
			}
		} while (too_close);
		planet[i].x = x;
		planet[i].y = y;
		planet[i].z = z;
		sprintf(name, "Planet %d", i); /* TODO: something better */
		planet[i].name = strdup(name);
		nplanets = i;
	}
}

static void print_planets(void)
{
	int i;

	printf("Planets:\n");
	for (i = 0; i < nplanets; i++) {
		printf("  Planet %d: %s, %f, %f, %f\n", i, planet[i].name,
			planet[i].x, planet[i].y, planet[i].z);
	}
	printf("\n");
}

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
		c->thirdpp = strdup("him");
		c->thirdself = strdup("himself");
		c->Third = strdup("He");
	} else {
		c->firstname = expand_macros("[female-firstname]");
		c->middlename = expand_macros("[female-firstname]");
		c->third = strdup("she");
		c->thirdp = strdup("her");
		c->thirdpp = strdup("her");
		c->thirdself = strdup("herself");
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

static void generate_planetary_location(int planet_number)
{
	char name[100];

	if (nlocations >= MAX_LOCATIONS)
		return;
	sprintf(name, "[planetary_location_name] %d", nlocations);
	location[nlocations].name = expand_macros(name);
	location[nlocations].description = expand_macros("[planetary_location_description]");
	location[nlocations].x = planet[planet_number].x + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].y = planet[planet_number].y + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].z = planet[planet_number].z + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].planet = planet_number;
	location[nlocations].type = LOCATION_TYPE_PLANETARY;
	location[nlocations].nconnections = 0;
	nlocations++;
}

static void generate_spaceship_location(void)
{
	char name[100];
	int p;

	if (nlocations >= MAX_LOCATIONS)
		return;
	sprintf(name, "[spaceship_location_name] %d", nlocations);
	location[nlocations].name = expand_macros(name);
	location[nlocations].description = expand_macros("[spaceship_location_description]");
	p = rand() % nplanets;
	location[nlocations].x = planet[p].x + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].y = planet[p].y + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].z = planet[p].z + 100.0 * ((double) rand() / (double) RAND_MAX);
	location[nlocations].planet = p;
	location[nlocations].type = LOCATION_TYPE_SPACESHIP;
	location[nlocations].nconnections = 0;
	nlocations++;
}

static void generate_locations(void)
{
	int done = 0;
	int i, j;
	for (i = 0; i < nplanets; i++) {
		for (j = 0; j < NLOCS_PER_PLANET; j++)
			generate_planetary_location(i);
	}
	for (i = 0; i < MAX_SPACESHIPS; i++) {
		generate_spaceship_location();
	}
}

static void print_locations(void)
{
	int i;

	for (i = 0; i < nlocations; i++) {
		switch (location[i].type) {
		case LOCATION_TYPE_PLANETARY:
			printf("Location %d: planetary, %s, on planet %d, %s\n",
				i, location[i].name, location[i].planet, location[i].description);
			break;
		case LOCATION_TYPE_SPACESHIP:
			printf("Location %d: spaceship, %s, on planet %d, %s\n",
				i, location[i].name, location[i].planet, location[i].description);
			break;
		default:
			printf("Location %d: unknown type %d, %s, on planet %d, %s\n",
				i, location[i].type, location[i].name, location[i].planet,  location[i].description);
			break;
		}
	}
}

static void add_planetary_connection(int a, int b)
{
	char *via; /* e.g. horseback, landspeeder, spaceship, walking, etc. */
	int from, to;
	int n;

	n = location[a].nconnections;
	location[a].connection[n].to = b;
	location[a].connection[n].from = a;
	location[a].connection[n].via = expand_macros("[planetary_connection_via]");
	location[a].nconnections++;
	n = location[b].nconnections;
	location[b].connection[n].to = a;
	location[b].connection[n].from = b;
	location[b].connection[n].via = expand_macros("[planetary_connection_via]");
	location[b].nconnections++;
}

static void generate_location_connections(void)
{
	int i, j;
	float dist, dx, dy, dz;

	/* Connect all locations on the same planet together */
	for (i = 0; i < nlocations; i++) {
		if (location[i].type == LOCATION_TYPE_SPACESHIP)
			continue;
		if (i == j)
			continue; /* do not self connect */
		for (j = 0; j < nlocations; j++) {
			if (location[j].type == LOCATION_TYPE_SPACESHIP)
				continue;
			dx = location[i].x - location[j].x;
			dy = location[i].y - location[j].y;
			dz = location[i].z - location[j].z;
			dist = sqrt(dx * dx + dy * dy + dz * dz);
			if (dist < 1000.0)
				add_planetary_connection(i, j);
		}
	}
}

static void assign_characters_locations(void)
{
	int i, n;

	for (i = 0; i < MAXCHARS; i++)
		cast[i].location = rand() % nlocations;
}

/* param should be "p1" or "p2", role should be "hero", or "antagonist" */
void teardown_character_param(char *param, char *role)
{
	char p[100];
	sprintf(p, "%s", param);
	clear_macro("common_words", p); /* "p1", "[hero]" */
	sprintf(p, "%spp", param);
	clear_macro("common_words", p); /* "p1pp", "[heropp]" */
	sprintf(p, "%sp", param);
	clear_macro("common_words", p); /* "p1p", "[herop]" */
	sprintf(p, "%sself", param);
	clear_macro("common_words", p); /* "p1self", "[heroself]" */
}

/* param should be "p1" or "p2", role should be "hero", or "antagonist" */
void setup_character_param(char *param, char *role)
{
	char p[100], r[100];
	teardown_character_param(param, role);
	sprintf(p, "%s", param); sprintf(r, "[%s]", role);
	add_macro("common_words", p, r); /* "p1", "[hero]" */
	sprintf(p, "%spp", param); sprintf(r, "[%spp]", role);
	add_macro("common_words", p, r); /* "p1pp", "[heropp]" */
	sprintf(p, "%sp", param); sprintf(r, "[%sp]", role);
	add_macro("common_words", p, r); /* "p1p", "[herop]" */
	sprintf(p, "%sself", param); sprintf(r, "[%sself]", role);
	add_macro("common_words", p, r); /* "p1self", "[heroself]" */
}

void introduction(void)
{
	print("Introduction\n\n");
	/* print("[intro]\n\n"); */

}

void ordinary_world(void)
{
	print("The Ordinary World\n\n");
	setup_character_param("p1", "hero");
	setup_character_param("p2", "antagonist");
	char *setting = expand_macros_by_type("{setting}\n\n", '{');
	print(setting);
	print("[the-ordinary-world]\n\n");
}


#if 0
void tests_allies_and_enemies(void)
{
	print("Tests, Allies, and Enemies\n\n");
	setup_character_param("p1", "hero");
	setup_character_param("p2", "antagonist");
	print("[fight_scene]\n\n");
}
#endif

static void move_character(int i, int pov)
{
	int n;
	int from, to;
	char *via;

	if (location[cast[i].location].nconnections == 0) {
		if (location[cast[i].location].type != LOCATION_TYPE_SPACESHIP) {
			printf("BUG: location %d has no connections but is not a spaceship\n",
				cast[i].location);
		}
		do {
			n = rand() % nlocations;
		} while (location[n].type != LOCATION_TYPE_PLANETARY);
		from = cast[i].location;
		to = n;
		via = expand_macros("[spaceship_travel]");
	} else {
		n = rand() % location[cast[i].location].nconnections;
		from = location[cast[i].location].connection[n].from;
		to = location[cast[i].location].connection[n].to;
		via = expand_macros(location[cast[i].location].connection[n].via);
	}
	printf("%s chooses to move from %s to %s via %s.\n", cast[i].firstname,
		location[from].name, location[to].name, via);
	free(via);
}

#define ACTION_MOVE 0
#define ACTION_THINK 1
#define MAX_ACTIONS 2
void dont_just_stand_there_do_something(int i, int pov)
{
	int action;

	action = rand() % MAX_ACTIONS;
	switch (action) {
	case ACTION_MOVE:
		move_character(i, pov);
		break;
	case ACTION_THINK:
		if (i == pov)
			printf("%s chooses to think.\n", cast[i].firstname);
		break;
	default:
		break;
	}
}

void simulate(void)
{
#define MOVES 100
#define MOVES_PER_CHAR 10
	int i, j;
	int pov = 0;

	for (i = 0; i < MOVES; i++) {
		if ((i % MOVES_PER_CHAR) == 0)
			pov = (pov + 1) % MAXCHARS;
		for (j = 0; j < MAXCHARS; j++)
			dont_just_stand_there_do_something(j, pov);
	}
}

int main(int argc, char *argv[])
{
	init_macros();
	randomize(0);
	generate_characters();
	generate_planets();
	generate_locations();
	generate_location_connections();
	assign_characters_locations();
	print_planets();
	print_locations();
	add_macro("common_words", "Hero", cast[0].firstname);
	add_macro("common_words", "hero3", cast[0].third);
	add_macro("common_words", "herop", cast[0].thirdp);
	add_macro("common_words", "heroself", cast[0].thirdself);
	add_macro("common_words", "heropp", cast[0].thirdpp);
	add_macro("common_words", "antagonist", cast[1].firstname);
	add_macro("common_words", "antagonist3", cast[1].third);
	add_macro("common_words", "antagonistp", cast[1].thirdp);
	add_macro("common_words", "antagonistpp", cast[1].thirdpp);
	add_macro("common_words", "antagonistself", cast[1].thirdself);
	randomize(0);
	/* Let's try modelling after Joseph Campbell's Hero's Journey */
	introduction();
	simulate();
	return 0;
}
