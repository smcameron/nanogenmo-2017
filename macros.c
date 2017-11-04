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

#include "macros.h"
#include "arraysize.h"

#if 0
struct macro {
	char *name;
	int nalts;
	char *alt[0];
};
#endif

char *intro[] = {
	"[beginning], [peaceful-happening] and [peaceful-happening]. "
	"Then [began] a [timeperiod] of [unrest]. Rebel [spaceship]s, [striking] "
	"from a [hidden] [base], have won their first [victory] against the "
	"[evil] [foe].  During the [battle], Rebel spies managed "
	"to [steal] [hidden] [plan]s to the [foe]'s ultimate weapon, the "
	"[ultimate] [ultimateweapon], an [ultimateweapon] with enough power to "
	"[destroy] an entire [planet].  Pursued by the [foe]'s [evil] "
	"agents, [hero] [flee]s home aboard her [spaceship], [custodian] "
	"of the stolen [hidden] [plan]s that can save her people and restore freedom "
	"to the galaxy....",
};

char *spaceship[] = {
	"starship",
	"spaceship",
	"destroyer",
	"cruiser",
	"battlestar",
};

char *striking[] = {
	"striking",
	"attacking",
	"assaulting",
	"assailing",
};

char *hidden[] = {
	"hidden",
	"concealed",
	"sequestered",
	"unknown",
	"clandestine",
	"secret",
};

char *base[] = {
	"base",
	"starbase",
	"base of operations",
	"headquarters",
};

char *battle[] = {
	"battle",
	"conflict",
	"fight",
	"engagement",
	"fighting",
	"firefight",
};

char *plan[] = {
	"plan",
	"blueprint",
	"document",
	"database",
};

char *beginning[] = {
	"In the beginning",
	"At the outset",
	"In the early dawn of our story",
	"At the inception of all this business",
	"In the origination of this tale",
	"At the genesis of this journey",
	"In the emergence of all this",
	"At the start",
	"At the commencement",
};

char *birds[] = {
	"loons",
	"eagles",
	"bluejays",
	"birds",
	"feathered creatures",
	"larks",
	"swans",
	"ducks",
};

char *chirping[] = {
	"chirping",
	"singing",
	"calling",
	"making bird sounds",
};

char *flowers[] = {
	"flowers",
	"roses",
	"daffodils",
	"daisies",
	"bluebonnets",
	"honeysuckle",
};

char *strongdrink[] = {
	"wine",
	"beer",
	"whiskey",
	"rum",
	"vodka",
	"tequila",
	"cocktails",
};

char *plentiful[] = {
	"plentiful",
	"easy to come by",
	"abundant",
	"easy",
	"everywhere",
};

char *food[] = {
	"food",
	"victuals",
	"meal",
	"beef",
	"pork",
	"nourishment",
	"sustenance",
	"feast",
	"bread",
	"meat",
	"venison",
	"fish",
};

char *good[] = {
	"good",
	"excellent",
	"wonderful",
	"enjoyable",
	"pleasant",
	"agreeable",
	"suitable",
	"perfect",
};

char *not_expensive[] = {
	"cheap",
	"not expensive",
	"inexpensive",
	"easy to come by",
};

char *peaceful_happening[] = {
	"the [birds] were [chirping]",
	"the wind blew gently",
	"the children played happily",
	"the [flowers] were sweet",
	"the [strongdrink] was [plentiful], and the [food] was [good] and [not-expensive]",
	"[peace] was on the [land]",
	"we were [happy]",
	"things were [good]",
	"all was well",
	"the streets were filled with festival goers",
};

char *planet[] = {
	"planet",
	"world",
};

char *evil[] = {
	"evil",
	"sinister",
	"vile",
	"wicked",
	"despicable",
	"heartless",
	"terrible",
};

char *foe[] = {
	"foe",
	"villian",
	"enemy",
};

char *victory[] = {
	"victory",
	"triumph",
	"conquest",
};

char *ultimate[] = {
	"ultimate",
	"final",
	"super",
};

char *ultimateweapon[] = {
	"gigablaster",
	"quarkbomber",
	"planetmelter",
	"superannihilator",
};

char *unrest[] = {
	"unrest",
	"strife",
	"conflict",
	"war",
	"turmoil",
	"uncertainty",
	"civil war",
	"rebellion",
	"danger",
};

char *timeperiod[] = {
	"period",
	"time",
	"interval",
	"era",
	"age",
	"epoch",
};

char *began[] = {
	"began",
	"there was",
	"commenced",
	"started",
	"ensued",
	"happened",
};

char *steal[] = {
	"steal",
	"pilfer",
	"obtain",
	"lift",
	"abscond with",
	"take",
	"liberate",
};

char *custodian[] = {
	"custodian",
	"caretaker",
	"keeper",
	"guardian",
	"steward",
	"protector",
};

char *flee[] = {
	"flee",
	"race",
	"fly",
	"travel",
	"run",
	"retreat",
};

char *surnames[] = {
#include "lastnames.h"
};

char *malefirstnames[] = {
#include "male_firstnames.h"
};

char *femalefirstnames[] = {
#include "female_firstnames.h"
};

char *charactertitle[] = {
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"M.",
	"Dr.",
	"Detective",
	"Captain",
	"Private",
	"King",
	"Corporal",
	"Colonel",
	"Admiral",
	"Pilot",
	"President",
	"Reverend",
	"Ambassador",
};

char *theordinaryworld[] = {
	"[theordworld1]",
};

char *theordworld1[] = {
	"[heroworksjob]. [heroisbored]. [herowantsadventure]. [herodreams]",
	"[heroisbored]. [heroneedsjob]. [heroisbored]. [herodrinks]. [herodreams]",
};

char *heroisbored[] = {
	"[hero] [looks] out the window",
	"[hero] [looks] at the clock",
	"[hero] wonders what time it is",
};

char *heroworksjob[] = {
	"[hero] types in a few more entries",
	"[hero] sweeps the deck",
	"[hero] empties the wastebasket",
	"[hero] flushes the toilet",
	"[hero] ponders the universe and what it all means",
	"[hero] [thinks-about] what he might have for lunch",
	"[hero] [thinks-about] what it must have been like in the old days",
	"[hero] [thinks-about] how things might have been different",
};

char *herowantsadventure[] = {
	"[hero] [wants] [adventureidea]"
};

char *wants[] = {
	"wants",
	"desires",
	"craves",
	"needs",
	"really needs",
	"desperately wants",
	"will go out of his mind without",
};

char *adventureidea[] = {
	"some kind of adventure",
	"some kind of excitement",
	"something better than this life, something exciting",
	"a way out of here to something better",
	"adventure, some way out of here",
	"a way to shake things up, a change from this routine",
};

char *herodreams[] = {
	"[hero] dreams about running away from it all",
	"[hero] [thinks about] dropping everything and hitting the road", 
	"[hero] [thinks about] quitting this job", 
	"[hero] [thinks about] travelling the galaxy", 
	"[hero] [thinks about] where things went wrong", 
	"[hero] [thinks about] how things could be better", 
	"[hero] [thinks about] how to get life back together", 
};

char *heroneedsjob[] = {
	"[hero] [thinks-about] where to get the money",
	"[hero] [thinks-about] how to make a living.",
	"[hero] [needs] a job.",
	"[hero] [needs] a way to make money.",
};

char *needs[] = {
	"needs",
	"requires",
	"desparately needs",
	"is in need of",
	"can't do without",
	"suffers from a lack of",
};

char *herodrinks[] = {
	"[hero] pours a drink of [strongdrink]",
	"[hero] sips a [strongdrink]",
	"[hero] lifts a glass of [strongdrink]",
	"[hero] slams down a [strongdrink]",
	"[hero] [thinks-about] a [strongdrink]",
};

char *thinksabout[] = {
	"thinks about",
	"considers",
	"ponders",
	"imagines",
};

char *looks[] = {
	"stares",
	"looks",
	"takes a look",
};

struct macro common_words[] = {
	{ "beginning", ARRAYSIZE(beginning), beginning },
	{ "peaceful-happening", ARRAYSIZE(peaceful_happening), peaceful_happening },
	{ "birds", ARRAYSIZE(birds), birds },
	{ "chirping", ARRAYSIZE(chirping), chirping },
	{ "flowers", ARRAYSIZE(flowers), flowers },
	{ "strongdrink", ARRAYSIZE(strongdrink), strongdrink },
	{ "plentiful", ARRAYSIZE(plentiful), plentiful },
	{ "food", ARRAYSIZE(food), food },
	{ "not-expensive", ARRAYSIZE(not_expensive), not_expensive },
	{ "intro", ARRAYSIZE(intro), intro },
	{ "battle", ARRAYSIZE(battle), battle },
	{ "base", ARRAYSIZE(base), base },
	{ "hidden", ARRAYSIZE(hidden), hidden },
	{ "striking", ARRAYSIZE(striking), striking },
	{ "spaceship", ARRAYSIZE(spaceship), spaceship },
	{ "evil", ARRAYSIZE(evil), evil },
	{ "foe", ARRAYSIZE(foe), foe },
	{ "plan", ARRAYSIZE(plan), plan },
	{ "planet", ARRAYSIZE(planet), planet },
	{ "victory", ARRAYSIZE(victory), victory },
	{ "ultimate", ARRAYSIZE(ultimate), ultimate },
	{ "ultimateweapon", ARRAYSIZE(ultimateweapon), ultimateweapon },
	{ "unrest", ARRAYSIZE(unrest), unrest },
	{ "timeperiod", ARRAYSIZE(timeperiod), timeperiod },
	{ "began", ARRAYSIZE(began), began },
	{ "steal", ARRAYSIZE(steal), steal },
	{ "custodian", ARRAYSIZE(custodian), custodian },
	{ "flee", ARRAYSIZE(flee), flee },
	{ "male-firstname", ARRAYSIZE(malefirstnames), malefirstnames },
	{ "female-firstname", ARRAYSIZE(femalefirstnames), femalefirstnames },
	{ "surname", ARRAYSIZE(surnames), surnames },
	{ "character-title", ARRAYSIZE(charactertitle), charactertitle },
	{ "the-ordinary-world", ARRAYSIZE(theordinaryworld), theordinaryworld },
	{ "theordworld1", ARRAYSIZE(theordworld1), theordworld1 },
	{ "heroisbored", ARRAYSIZE(heroisbored), heroisbored },
	{ "looks", ARRAYSIZE(looks), looks },
	{ "heroworksjob", ARRAYSIZE(heroworksjob), heroworksjob },
	{ "heroneedsjob", ARRAYSIZE(heroneedsjob), heroneedsjob },
	{ "herodrinks", ARRAYSIZE(herodrinks), herodrinks },
	{ "thinks-about", ARRAYSIZE(thinksabout), thinksabout },
	{ "needs", ARRAYSIZE(needs), needs },
	{ "herodreams", ARRAYSIZE(herodreams), herodreams },
	{ "herowantsadventure",  ARRAYSIZE(herowantsadventure), herowantsadventure },
	{ "wants", ARRAYSIZE(wants), wants },
	{ "adventureidea", ARRAYSIZE(adventureidea), adventureidea },
};

static struct macro_set_entry *macro_set = NULL;
static int nmacro_sets = 0;
char **macro_set_name = NULL;

void add_macro_set(char *setname)
{
	macro_set_name = realloc(macro_set_name, sizeof(char *) * (nmacro_sets + 1));
	macro_set_name[nmacro_sets] = strdup(setname);
	macro_set = realloc(macro_set, sizeof(*macro_set) * (nmacro_sets + 1));
	memset(&macro_set[nmacro_sets], 0, sizeof(*macro_set));
	macro_set[nmacro_sets].m = NULL;
	macro_set[nmacro_sets].nmacros = 0;
	nmacro_sets++;
}

void add_macro(char *setname, char *name, char *alt)
{
	int i, j, k;

	for (i = 0; i < nmacro_sets; i++) {
		if (strcmp(macro_set_name[i], setname) != 0)
			continue;
		for (j = 0; j < macro_set[i].nmacros; j++) {
			if (strcmp(macro_set[i].m[j].name, name) == 0) {
				for (k = 0; k < macro_set[i].m[j].nalts; k++) {
					if (strcmp(macro_set[i].m[j].alt[k], alt) == 0)
						return; /* this macro is already present */
				}
				macro_set[i].m[j].alt = realloc(macro_set[i].m[j].alt, sizeof(char *) * (macro_set[i].m[j].nalts + 1));
				macro_set[i].m[j].alt[macro_set[i].m[j].nalts] = strdup(alt);
				macro_set[i].m[j].nalts++;
				return;
			}
		}
		/* Didn't find this macro at all, add it, plus the new alt entry */
		macro_set[i].m = realloc(macro_set[i].m, sizeof(*macro_set[i].m) * (macro_set[i].nmacros + 1));
		macro_set[i].m[macro_set[i].nmacros].alt = malloc(sizeof(char *));
		macro_set[i].m[macro_set[i].nmacros].name = strdup(name);
		macro_set[i].m[macro_set[i].nmacros].alt[0] = strdup(alt);
		macro_set[i].m[macro_set[i].nmacros].nalts = 1;
		macro_set[i].nmacros++;
		return;
	}
}

void remove_macro(char *setname, char *name, char *alt)
{
	int i, j, k;

	for (i = 0; i < nmacro_sets; i++) {
		if (strcmp(macro_set_name[i], setname) != 0)
			continue;
		for (j = 0; j < macro_set[i].nmacros; j++) {
			if (strcmp(macro_set[i].m[j].name, name) == 0) {
				for (k = 0; k < macro_set[i].m[j].nalts; k++) {
					if (strcmp(macro_set[i].m[j].alt[k], alt) == 0) {
						if (k == macro_set[i].m[j].nalts - 1) {
							macro_set[i].m[j].nalts--;
							return;
						}
						memmove(&macro_set[i].m[j].alt[k], &macro_set[i].m[j].alt[k + 1],
								(macro_set[i].m[j].nalts - k) * sizeof(char *));
						macro_set[i].m[j].nalts--;
						return;
					}
				}
				return; /* Macro wasn't present to begin with */
			}
		}
	}
}

static char *find_matching_close_bracket(char *s)
{
	int count = 0;
	for (; *s != '\0'; s++) {
		if (*s == '[')
			count++;
		if (*s == ']')
			count--;
		if (count == 0)
			return s;
	}
	return NULL;
}

static char *substitute(char *input)
{
	int i, j;

	for (i = 0; i < nmacro_sets; i++) {
		struct macro_set_entry *mse = &macro_set[i];
		for (j = 0; j < mse->nmacros; j++) {
			struct macro *m = &mse->m[j];
			if (strcmp(m->name, input) == 0) {
				return strdup(m->alt[rand() % m->nalts]);
			}
		}
	}
	return strdup(input);
}

char *expand_macros(char *input)
{
	char *open_bracket = index(input, '[');
	char *beginning, *middle, *expanded_middle, *ending, *whole;

	if (!open_bracket) {
		char *e, *sub = substitute(input);
		if (!index(sub, '['))
			return sub;
		e = expand_macros(sub);
		free(sub);
		return e;
	}
	char *close_bracket = find_matching_close_bracket(open_bracket);
	if (!close_bracket)
		return strdup(input);
	int len = open_bracket - input;
	if (len > 0) {
		beginning = malloc(len + 1);
		strncpy(beginning, input, len);
		beginning[len] = '\0';
	} else {
		beginning = strdup("");
	}
	ending = expand_macros(close_bracket + 1);
	len = close_bracket - open_bracket - 1;
	middle = malloc(len + 1);
	strncpy(middle, open_bracket + 1, len);
	middle[len] = '\0';
	expanded_middle = expand_macros(middle);
	free(middle);
	whole = malloc(strlen(beginning) + strlen(expanded_middle) + strlen(ending) + 1);	
	sprintf(whole, "%s%s%s", beginning, expanded_middle, ending);
	free(beginning);
	free(expanded_middle);
	free(ending);
	return whole;
}

void init_macros(void)
{
	int i, j, k;

	add_macro_set("common_words");

	for (i = 0; i < ARRAYSIZE(common_words); i++)
		for (j = 0; j < common_words[i].nalts; j++)
			add_macro("common_words", common_words[i].name, common_words[i].alt[j]);
}
