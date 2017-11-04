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

struct macro_expansion_type {
	char begin;
	char end;
};

static struct macro_expansion_type macro_type[256]; /* indexed by open char '{' or '[' */

char *intro[] = {
	"[beginning], [peaceful-happening] and [peaceful-happening]. "
	"Then [began] a [timeperiod] of [unrest]. Rebel [spaceship]s, [striking] "
	"from a [hidden] [base], have won their first [victory] against the "
	"[evil] [foe].  During the [battle], Rebel spies managed "
	"to [steal] [hidden] [plan]s to the [foe]'s ultimate weapon, the "
	"[ultimate] [ultimateweapon], an [ultimateweapon] with enough power to "
	"[destroy] an entire [planet].  Pursued by the [foe]'s [evil] "
	"agents, [hero] [flee]s home aboard [hero3p] [spaceship], [custodian] "
	"of the stolen [hidden] [plan]s that can save [hero3p] people and restore freedom "
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
	"cocktail",
	"shot of whiskey",
	"martini",
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

char *hero[] = {
	"[Hero]", /* first name */
	"[hero3]", /* he/she */
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
	"[hero] [thinks about] how to get [hero3p] life back together",
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

char *upholstered[] = {
	"upholstered",
	"covered",
};

char *gleaming[] = {
	"gleaming",
	"shining",
	"shiny",
	"sparkling",
};

char *spaceshipwalls[] = {
	"walls of the ship",
	"bulkheads",
	"wall panels",
};

char *fancy_metal[] = {
	"hyperdyne steelium",
	"neutronic aluminum",
	"titanium",
	"gold plated hypersteel",
	"a platinum-steel alloy",
};

char *luxurious[] = {
	"luxurious",
	"opulent",
	"decadent",
	"exquisite",
	"expensive",
	"sumptuous",
	"splendid",
	"magnificent",
	"extravagant",
	"fancy",
};

char *animal_hide[] = {
	"leather",
	"soft leather",
	"hide of [planetary_origin] space whales",
	"skins of [planetary_origin] tigerbats",
	"animal hides from all over the galaxy",
};

char *amazing[] = {
	"beautiful",
	"wonderful",
	"amazing",
	"astounding",
	"breathtaking",
	"stunning",
	"staggering",
	"awesome",
	"impressive",
	"wondrous",
	"terrific",
	"awe inspiring",
};

char *musical_instrument[] = {
	"guitar",
	"piano",
	"flute",
	"Arcturan lyre",
	"subharmonic traumaphone",
	"Gonkan windpipe",
};

char *beautiful_space_view[] = {
	"[amazing] view of the planet below",
	"[amazing] view of the distant stars outside",
	"[amazing] view of the planet's moon",
};

static char *body_part[] = {
	"head",
	"back",
	"leg",
	"arm",
	"wrist",
	"stomach",
	"belly",
	"torso",
	"chest",
	"face",
	"nose",
	"mouth",
	"eye",
	"neck",
};

static char *animal[] = {
	"koala",
	"elephant",
	"leopard",
	"frog",
	"chihuahua",
	"goat",
	"mouse",
	"moose",
	"tortoise",
	"chicken",
	"pig",
	"walrus",
	"wombat",
	"kangaroo",
	"eagle",
	"dolphin",
};

static char *body_size[] = {
	"enormous",
	"tiny",
	"huge",
	"great",
	"[animal]-sized",
	"hulking",
	"squat",
	"short",
	"tall thin",
	"globular",
	"spindly",
	"glutinous",
};

static char *drinking[] = {
	"drinking",
	"sipping",
	"quaffing",
	"nursing",
	"sucking",
	"slurping",
	"ingesting",
	"siphoning",
};

static char *simplespacedrink[] = {
	"[strongdrink]",
	"Dawnsnuffler",
	"Spacewalker Red",
	"Jugo",
	"juiced vorlon",
	"Wandering Zarkon",
	"Confuser",
};

static char *drinking_vessel[] = {
	"flask",
	"flagon",
	"cup",
	"glass",
	"cylinder",
	"decanter",
	"mug",
	"carafe",
	"pitcher",
	"snifter",
	"snorkler",
	"injector",
	"pipe",
	"capsule",
	"tankard",
};

static char *spacedrink[] = {
	"a [drinking_vessel] of [planetary_origin] [simplespacedrink]",
	"a [planetary_origin] [simplespacedrink]",
	"a [drinking_vessel] of [simplespacedrink]",
	"a [simplespacedrink] in a [drinking_vessel]",
	"a [simplespacedrink]",
};

static char *planetary_origin[] = {
	"Arcturan",
	"Norkunian",
	"Fontobian",
	"Skornallan",
	"Vekkazi",
	"Wallunian",
	"Zarkon",
	"Schaazbaut",
	"Sordoban",
};

static char *space_locale[] = {
	"the far reaches of the Zarkon colonies",
	"the shoulder of Orion",
	"Orion's nether regions",
	"somewhere in the Andromeda region",
	"parts unknown",
	"the inner arm of the Vorlon spiral",
	"a planet in the near arm of the [planetary_origin] galaxy",
	"the neutral zone",
	"the [planetary_origin] nebula",
	"the far side of the [planetary_origin] formation",
	"a little known planet in colonies",
};

static char *alien_type[] = {
	"Boggo",
	"Waffabee",
	"Korpon",
	"Quimbo",
	"Borlion",
	"Wandulian",
};

static char *small_number[] = {
	"two",
	"three",
	"four",
	"five",
	"six",
};

static char *alien_appendages[] = {
	"[small_number] multi-jointed limbs terminated with [small_number] fingerlings",
	"[small_number] tentacles",
	"very long arms",
	"very short appendages",
	"pair of antennae",
	"[small_number] jointed stalks",
};

static char *alien_eyes[] = {
	"[small_number] eyes",
	"[small_number] [color] eyes",
	"[small_number] [color] small eyes",
	"[small_number] huge eyes",
	"[small_number] eyeslits",
	"[small_number] eyestalks",
};

static char *skin_pattern[] = {
	"spotted",
	"striped",
	"uniform",
	"shining",
	"iridescent",
	"faintly glowing",
	"slightly smoking",
};

static char *color[] = {
	"green",
	"reddish",
	"purple",
	"black",
	"gray",
	"pink",
	"orange",
	"pale yellow",
	"pale green",
	"blue",
	"pale blue",
};

static char *skin_texture[] = {
	"slimy",
	"smooth",
	"bumpy",
	"scaly",
	"crusty",
	"oozing",
};

static char *skin[] = {
	"hide",
	"skin",
	"fur",
	"hair",
	"carapace",
	"chitin",
	"armor plating",
	"membrane",
};

static char *alien_skin[] = {
	"[color] [skin_pattern] [skin_texture] [skin]",
	"[skin_texture] [skin]",
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
	{ "upholstered", ARRAYSIZE(upholstered), upholstered },
	{ "luxurious", ARRAYSIZE(luxurious), luxurious },
	{ "animal_hide", ARRAYSIZE(animal_hide), animal_hide },
	{ "gleaming", ARRAYSIZE(gleaming), gleaming },
	{ "spaceshipwalls", ARRAYSIZE(spaceshipwalls), spaceshipwalls },
	{ "beautiful_space_view", ARRAYSIZE(beautiful_space_view), beautiful_space_view },
	{ "fancy_metal", ARRAYSIZE(fancy_metal), fancy_metal },
	{ "hero", ARRAYSIZE(hero), hero },
	{ "body_part", ARRAYSIZE(body_part), body_part },
	{ "body_size", ARRAYSIZE(body_size), body_size },
	{ "drinking", ARRAYSIZE(drinking), drinking },
	{ "planetary_origin", ARRAYSIZE(planetary_origin), planetary_origin },
	{ "space_locale", ARRAYSIZE(space_locale), space_locale },
	{ "alien_type", ARRAYSIZE(alien_type), alien_type },
	{ "alien_appendages", ARRAYSIZE(alien_appendages), alien_appendages },
	{ "alien_eyes", ARRAYSIZE(alien_eyes), alien_eyes },
	{ "skin_texture", ARRAYSIZE(skin_texture), skin_texture },
	{ "skin_pattern", ARRAYSIZE(skin_pattern), skin_pattern },
	{ "alien_skin", ARRAYSIZE(alien_skin), alien_skin },
	{ "color", ARRAYSIZE(color), color },
	{ "small_number", ARRAYSIZE(small_number), small_number },
	{ "spacedrink", ARRAYSIZE(spacedrink), spacedrink },
	{ "drinking_vessel", ARRAYSIZE(drinking_vessel), drinking_vessel },
	{ "simplespacedrink", ARRAYSIZE(simplespacedrink), simplespacedrink },
	{ "amazing", ARRAYSIZE(amazing), amazing },
	{ "animal", ARRAYSIZE(animal), animal },
};

static char *fight_action1[] = {
	"lunged at",
	"swung at",
	"leaped on",
	"grappled with",
	"pushed",
	"moved towards",
	"backed away from",
	"looked warily at",
	"looked warily at",
	"scowled at",
	"carefully watched",
	"looked for a weakness in",
	"tried to figure out how to beat",
	"tried to scramble away from",
	"grabbed",
};

static char *fight_action2[] = {
	"howled in pain",
	"leaped to his feet",
	"got up slowly",
	"moved back",
	"charged",
	"fell to the ground",
	"grimaced",
	"groaned in pain",
	"cried out in pain",
	"breathed heavily",
	"was breathing heavily",
	"was getting tired",
	"was in pain",
	"was hurt",
	"was bleeding",
	"was out for blood",
	"felt the anger rising",
	"felt strong",
	"felt the rush of adrenaline",
	"drew a knife",
	"drew a pistol",
};

static char *fight_action3[] = {
	"struck at",
	"reached for",
	"pounded",
	"hit",
	"punched",
	"shot at",
	"fired at",
	"aimed for",
	"tried to hit",
	"tried to punch",
	"tried to strike",
	"tried to stab",
	"stabbed",
	"kicked at",
	"kicked",
	"tried to kick",
};

static char *fight_sentence[] = {
	"[p1] [fight_action1] [p2pp].",
	"[p2] [fight_action1] [p1pp].",
	"[p1] [fight_action2].",
	"[p2] [fight_action2].",
	"[p2] [fight_action3] [p1p] [body_part].",
	"[p1] [fight_action3] [p2p] [body_part].",
	"[p1] [fight_action3] [p2].",
	"[p2] [fight_action3] [p1].",
	"[p1] [fight_action3] [p2pp].",
	"[p2] [fight_action3] [p1pp].",
	"[p2] clenched [p2p] fists.",
	"[p1] clenched [p1p] fists.",
	"[p1] braced [p1self].",
	"[p2] braced [p2self].",
};

static char *fight_scene[] = {
	"[fight_sentence] [fight_sentence] [fight_sentence] [fight_sentence] [fight_sentence] [fight_sentence]",
};

static char *luxurious_spaceship_cabin[] = {
	"The chairs in the cabin of the [spaceship] were [upholstered] in [luxurious] [animal_hide]. "
	"The [spaceshipwalls] were made of [fancy_metal]. A [gleaming] console was "
	"located near the front of the room. A large viewscreen afforded a [beautiful_space_view].",
};

static char *spaceship_interior1[] = {
};

static char *bar_char[] = {
	"a [body_size] [planetary_origin] [alien_type] with [alien_appendages] covered with [alien_skin] and [alien_eyes] [drinking] a [spacedrink]",
	"[drinking] a [spacedrink], a [body_size] [alien_type] from [space_locale] with [alien_eyes] and [alien_appendages] covered with [alien_skin]",
};

static char *spaceport_bar1[] = {
	"It was dimly lit in the. As [p1p] eyes adjusted to the light, [p1] could make out "
	"a variety of characters seated at the bar. Closest, [bar_char]. Next, [bar_char]. "
	"Then, [bar_char]. A rough crowd.",
};

static char *spaceship_interior[] = {
	"{luxurious_spaceship_cabin}",
#if 0
	"{military_spaceship_cabin}",
	"{cargo_spaceship_cabin}",
	"{pirate_spaceship_cabin}",
#endif
	"[spaceport_bar1]",
};

static char *setting[] = {
	"{spaceship_interior}",
#if 0
	"{spaceship_crash_site}",
#endif
};

static struct macro settings[] = {
	{ "setting", ARRAYSIZE(setting), setting },
	{ "spaceship_interior", ARRAYSIZE(spaceship_interior), spaceship_interior },
	{ "spaceport_bar1", ARRAYSIZE(spaceport_bar1), spaceport_bar1 },
	{ "bar_char", ARRAYSIZE(bar_char), bar_char },
	{ "luxurious_spaceship_cabin", ARRAYSIZE(luxurious_spaceship_cabin), luxurious_spaceship_cabin },
};

static struct macro scenes[] = {
	{ "fight_sentence", ARRAYSIZE(fight_sentence), fight_sentence },
	{ "fight_action1", ARRAYSIZE(fight_action1), fight_action1 },
	{ "fight_action2", ARRAYSIZE(fight_action2), fight_action2 },
	{ "fight_action3", ARRAYSIZE(fight_action3), fight_action3 },
	{ "fight_scene", ARRAYSIZE(fight_scene), fight_scene },
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

static char *find_matching_close_bracket(char *s, int type)
{
	int count = 0;
	for (; *s != '\0'; s++) {
		if (*s == macro_type[type].begin)
			count++;
		if (*s == macro_type[type].end)
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

char *expand_macros_by_type(char *input, int type)
{
	char *open_bracket = index(input, macro_type[type].begin);
	char *beginning, *middle, *expanded_middle, *ending, *whole;

	if (!open_bracket) {
		char *e, *sub = substitute(input);
		if (!index(sub, macro_type[type].begin))
			return sub;
		e = expand_macros_by_type(sub, type);
		free(sub);
		return e;
	}
	char *close_bracket = find_matching_close_bracket(open_bracket, type);
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
	expanded_middle = expand_macros_by_type(middle, type);
	free(middle);
	whole = malloc(strlen(beginning) + strlen(expanded_middle) + strlen(ending) + 1);	
	sprintf(whole, "%s%s%s", beginning, expanded_middle, ending);
	free(beginning);
	free(expanded_middle);
	free(ending);
	return whole;
}

char *expand_macros(char *input)
{
	return expand_macros_by_type(input, '[');
}

static void add_static_macro_set(char *setname, struct macro *m, int nmacros)
{
	int i, j;
	add_macro_set(setname);
	for (i = 0; i < nmacros; i++)
		for (j = 0; j < m[i].nalts; j++)
			add_macro(setname, m[i].name, m[i].alt[j]);
}

void init_macros(void)
{
	int i, j, k;

	macro_type['{'].begin = '{';
	macro_type['{'].end = '}';
	macro_type['['].begin = '[';
	macro_type['['].end = ']';

	add_static_macro_set("common_words", common_words, ARRAYSIZE(common_words));
	add_static_macro_set("settings", settings, ARRAYSIZE(settings));
	add_static_macro_set("scenes", scenes, ARRAYSIZE(scenes));
}
