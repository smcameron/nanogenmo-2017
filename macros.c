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

static char *intro[] = {
	"[beginning], [peaceful-happening] and [peaceful-happening]. "
	"Then [began] a [timeperiod] of [unrest]. Rebel [spaceship]s, [striking] "
	"from a [hidden] [base], have won their first [victory] against the "
	"[evil] [foe].  During the [battle], Rebel spies managed "
	"to [steal] [hidden] [plan]s to the [foe]'s ultimate weapon, the "
	"[ultimate] [ultimateweapon], an [ultimateweapon] with enough power to "
	"[destroy] an entire [planet].  Pursued by the [foe]'s [evil] "
	"agents, [hero] [flee]s home aboard [herop] [spaceship], [custodian] "
	"of the stolen [hidden] [plan]s that can save [herop] people and restore freedom "
	"to the galaxy....",
};

static char *spaceship[] = {
	"starship",
	"spaceship",
	"destroyer",
	"cruiser",
	"battlestar",
};

static char *spaceship_location_name[] = {
	"the Mayflower Wayward",
	"the Libra Lion",
	"the Cassiopeia AJAN",
	"the Early Fortune",
	"the Planeteer Jade",
	"the FAT Voidness",
	"the Lion Stellaron",
	"the Skyway ZAV",
	"the Stargrazer Stella",
	"the Wumpus Silencio",
	"the Revenge Libra",
	"the Starfire Stella",
	"the Capricorn Arrow",
	"the Galassia OPHUPH",
	"the Starfall Bulldog",
	"the Canis Perseus",
	"the CHACHII Velocita",
	"the Moongazer Lumiere",
	"the Roi Velocita",
	"the Early ZEFEB",
	"the PHARIU Topaz",
	"the Voidsky Arrow",
	"the Andromeda Delta",
	"the Tiempo OJAB",
	"the Orchid Cassiopeia",
	"the Potente Wrasse",
	"the Auriga Master",
	"the Nightsky Orchid",
	"the Montagne Starro",
	"the ROPH Deep",
	"the Starry Ray",
	"the Flame Carina",
	"the Vixen Skyway",
	"the Celestial Starling",
	"the Focus Galassia",
	"the Lamprey Heavenly",
	"the Lumino Cosmo",
	"the Potente Moongazer",
	"the Huntress Hopeful",
	"the Quarkion Charon",
	"the Stella Altair",
	"the DOLOU Swift",
	"the Gorgon Hopeful",
	"the Fargone Kastra",
	"the Distant Dame",
	"the Stellar Concept",
	"the Tempo Valkyrie",
	"the Gryphon Tiempo",
	"the Stellar TASPEI",
	"the Alto KOSH",
	"the Starman Starlorn",
	"the Porta APHIK",
	"the ASE Starro",
	"the SPUSOP Magna",
	"the Canis Golden",
	"the Magnifico MITOR",
	"the Tempo Axiom",
	"the Lontana OKED",
	"the Magnifico Tunstor",
	"the Golden STUPHIE",
	"the Galactic Avenger",
	"the Tiempo Cutter",
	"the Bulldog Cetus",
	"the Rapido Cutter",
	"the Zarmion Esteron",
	"the FIO Blacksky",
	"the Nebula Kastra",
	"the Axiom Alto",
	"the ITHA Darkness",
	"the Starfall Bear",
	"the Esploratore Bearcat",
	"the Early STIJI",
	"the Orca Starman",
	"the Farther Astro",
	"the BUJAI Fargone",
	"the Night TEI",
	"the Starward Stellar",
	"the Starry Stareyes",
	"the Pilote Voidsky",
	"the Celestial Starling",
	"the Kingfisher Space",
	"the MUE Stella",
	"the LAJ Skyway",
	"the Draco PHOBIE",
	"the CHII Wandering",
	"the Magna Valkyrie",
	"the Starlight Dog",
	"the Stellar DELAE",
	"the Delta Fargone",
	"the Lontana Norder",
	"the Tarantula Stellaron",
	"the MUVUA Tempo",
	"the SHICHAX Scorpius",
	"the Antares Valiant",
	"the Voidness MOSPOJ",
	"the Orion Silencio",
	"the Frontier Scorpius",
	"the Fury Andromeda",
	"the Tempo INA",
	"the Silent Avenger",
};

static char *striking[] = {
	"striking",
	"attacking",
	"assaulting",
	"assailing",
};

static char *hidden[] = {
	"hidden",
	"concealed",
	"sequestered",
	"unknown",
	"clandestine",
	"secret",
};

static char *base[] = {
	"base",
	"starbase",
	"base of operations",
	"headquarters",
};

static char *battle[] = {
	"battle",
	"conflict",
	"fight",
	"engagement",
	"fighting",
	"firefight",
};

static char *plan[] = {
	"plan",
	"blueprint",
	"document",
	"database",
};

static char *beginning[] = {
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

static char *birds[] = {
	"loons",
	"eagles",
	"bluejays",
	"birds",
	"feathered creatures",
	"larks",
	"swans",
	"ducks",
};

static char *chirping[] = {
	"chirping",
	"singing",
	"calling",
	"making bird sounds",
};

static char *flowers[] = {
	"flowers",
	"roses",
	"daffodils",
	"daisies",
	"bluebonnets",
	"honeysuckle",
};

static char *strongdrink[] = {
	"wine",
	"beer",
	"whiskey",
	"rum",
	"vodka",
	"tequila",
	"cocktail",
	"martini",
};

static char *plentiful[] = {
	"plentiful",
	"easy to come by",
	"abundant",
	"easy",
	"everywhere",
};

static char *food[] = {
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

static char *good[] = {
	"good",
	"excellent",
	"wonderful",
	"enjoyable",
	"pleasant",
	"agreeable",
	"suitable",
	"perfect",
};

static char *not_expensive[] = {
	"cheap",
	"not expensive",
	"inexpensive",
	"easy to come by",
};

static char *peaceful_happening[] = {
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

static char *planet[] = {
	"planet",
	"world",
};

static char *evil[] = {
	"evil",
	"sinister",
	"vile",
	"wicked",
	"despicable",
	"heartless",
	"terrible",
};

static char *foe[] = {
	"foe",
	"villian",
	"enemy",
};

static char *victory[] = {
	"victory",
	"triumph",
	"conquest",
};

static char *ultimate[] = {
	"ultimate",
	"final",
	"super",
};

static char *ultimateweapon[] = {
	"gigablaster",
	"quarkbomber",
	"planetmelter",
	"superannihilator",
};

static char *unrest[] = {
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

static char *timeperiod[] = {
	"period",
	"time",
	"interval",
	"era",
	"age",
	"epoch",
};

static char *began[] = {
	"began",
	"there was",
	"commenced",
	"started",
	"ensued",
	"happened",
};

static char *steal[] = {
	"steal",
	"pilfer",
	"obtain",
	"lift",
	"abscond with",
	"take",
	"liberate",
};

static char *custodian[] = {
	"custodian",
	"caretaker",
	"keeper",
	"guardian",
	"steward",
	"protector",
};

static char *flee[] = {
	"flee",
	"race",
	"fly",
	"travel",
	"run",
	"retreat",
};

static char *hero[] = {
	"[Hero]", /* first name */
	"[hero3]", /* he/she */
};

static char *surnames[] = {
#include "lastnames.h"
};

static char *malefirstnames[] = {
#include "male_firstnames.h"
};

static char *femalefirstnames[] = {
#include "female_firstnames.h"
};

static char *charactertitle[] = {
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

static char *theordinaryworld[] = {
	"theordinaryworld1",
};

static char *spaceshipgauges[] = {
	"propellant pressure",
	"engine status",
	"gauges",
	"switches",
	"life support system status",
	"warp drive coolant pressure",
	"warp drive status",
	"deflector shield status",
	"photon torpedo status",
	"phaser bank status",
	"attitude indicator",
	"flight trajectory",
};

static char *spaceshipdash[] = {
	"control panel",
	"dashboard",
};

static char *spaceshipsystem[] = {
	"warp drive",
	"auxiliary life support system",
	"main thrusters",
	"maneuvering thrusters",
	"tractor beam",
	"ship's scanners",
	"deflector shields",
};

static char *herospaceshipthings[] = {
	"[hero] checks the [spaceshipgauges] on the [spaceshipdash]",
	"[hero] powers up the [spaceshipsystem]",
	"[hero] powers down the [spaceshipsystem]",
	"[hero] engages the [spaceshipsystem]",
	"[hero] fires up the [spaceshipsystem]",
	"[hero] toggles [spaceshipsystem] on",
	"[hero] enters a course into the ship's computer",
};

static char *boards[] = {
	"boards",
	"gets aboard",
	"enters",
	"walks up the gangplank into",
	"climbs aboard",
	"climbs into",
};

static char *disembarks[] = {
	"disembarks from",
	"climbs out of",
	"walks down the gangplank of",
	"exits",
	"hops out of",
};

static char *spacecraft[] = {
	"spacecraft",
	"spaceship",
	"vessel",
	"ship",
};

static char *take_off[] = {
	"take off",
	"lift off",
	"blast off",
};

static char *spaceship_travel_embark[] = {
	"[hero] [boards] a [color] [spacecraft] and prepares to [take_off].",
};

static char *spaceship_travel_disembark[] = {
	"[hero] [disembarks] the [spacecraft].",
	"[hero] lowers the gangplank and [disembarks] the [spacecraft].",
};

static char *herothinks[] = {
	"[heroworksjob]. [heroisbored]. [herowantsadventure]. [herodreams]",
	"[heroisbored]. [heropondersjob]. [heroisbored]. [herodrinks]. [herodreams]",
};

static char *heroisbored[] = {
	"[hero] [looks] out the window",
	"[hero] [looks] at the clock",
	"[hero] wonders what time it is",
};

static char *heroworksjob[] = {
	"[hero] types in a few more entries",
	"[hero] sweeps the deck",
	"[hero] empties the wastebasket",
	"[hero] flushes the toilet",
	"[hero] ponders the universe and what it all means",
	"[hero] [thinks-about] what he might have for lunch",
	"[hero] [thinks-about] what it must have been like in the old days",
	"[hero] [thinks-about] how things might have been different",
};

static char *herowantsadventure[] = {
	"[hero] [wants] [adventureidea]"
};

static char *wants[] = {
	"wants",
	"desires",
	"craves",
	"needs",
	"really needs",
	"desperately wants",
	"will go out of his mind without",
};

static char *adventureidea[] = {
	"some kind of adventure",
	"some kind of excitement",
	"something better than this life, something exciting",
	"a way out of here to something better",
	"adventure, some way out of here",
	"a way to shake things up, a change from this routine",
};

static char *herodreams[] = {
	"[hero] dreams about running away from it all",
	"[hero] [thinks about] dropping everything and hitting the road", 
	"[hero] [thinks about] quitting this job", 
	"[hero] [thinks about] travelling the galaxy", 
	"[hero] [thinks about] where things went wrong", 
	"[hero] [thinks about] how things could be better", 
	"[hero] [thinks about] how to get [herop] life back together",
};

static char *heropondersjob[] = {
	"[hero] [thinks-about] where to get the money",
	"[hero] [thinks-about] how to make a living",
	"[hero] [needs] a job",
	"[hero] [needs] a way to make money",
	"[hero] [thinks-about] [herop] work as a [heroprofession]",
	"[hero] [thinks-about] becoming a [profession]",
};

static char *needs[] = {
	"needs",
	"requires",
	"desparately needs",
	"is in need of",
	"can't do without",
	"suffers from a lack of",
};

static char *herodrinks[] = {
	"[hero] pours a drink of [strongdrink]",
	"[hero] sips a [strongdrink]",
	"[hero] lifts a glass of [strongdrink]",
	"[hero] slams down a [strongdrink]",
	"[hero] [thinks-about] a [strongdrink]",
};

static char *thinksabout[] = {
	"thinks about",
	"considers",
	"ponders",
	"imagines",
};

static char *looks[] = {
	"stares",
	"looks",
	"takes a look",
};

static char *upholstered[] = {
	"upholstered",
	"covered",
};

static char *gleaming[] = {
	"gleaming",
	"shining",
	"shiny",
	"sparkling",
};

static char *spaceshipwalls[] = {
	"walls of the ship",
	"bulkheads",
	"wall panels",
};

static char *fancy_metal[] = {
	"hyperdyne steelium",
	"neutronic aluminum",
	"titanium",
	"gold plated hypersteel",
	"a platinum-steel alloy",
};

static char *luxurious[] = {
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

static char *animal_hide[] = {
	"leather",
	"soft leather",
	"hide of [planetary_origin] space whales",
	"skins of [planetary_origin] tigerbats",
	"animal hides from all over the galaxy",
};

static char *amazing[] = {
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

static char *musical_instrument[] = {
	"guitar",
	"piano",
	"flute",
	"Arcturan lyre",
	"subharmonic traumaphone",
	"Gonkan windpipe",
};

static char *beautiful_space_view[] = {
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

static char *rideable_animal[] = {
	"elephant",
	"horse",
	"camel",
	"dragon",
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
	"[drinking_vessel] of [planetary_origin] [simplespacedrink]",
	"[planetary_origin] [simplespacedrink]",
	"[drinking_vessel] of [simplespacedrink]",
	"[simplespacedrink] in a [drinking_vessel]",
	"[simplespacedrink]",
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
	"a little known planet in the colonies",
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

static char *space_company[] = {
	"Mulligan Heavy Industries",
	"Haxo Limited",
	"Neumann Spacecraft",
	"Holloway Propulsion",
	"InterStellar Commerce",
	"Intergalactic Holdings",
	"Gamma Five",
	"Arcturus Alpha",
	"Daxon Astro",
	"Zeexo Turbine",
	"Lightspeed",
	"Jaxoklon Skyways",
};

static char *profession[] = {
	"pilot",
	"farmer",
	"smuggler",
	"droid",
	"navigator",
	"droid technician",
	"gambler",
	"hustler",
	"detective",
	"detective for [space_company]",
	"archaeologist",
	"shepherd",
	"lawyer for [space_company]",
	"droid programmer for [space_company]",
	"droid programmer",
	"real estate broker",
	"mechanic",
	"scientist",
	"doctor",
	"soldier",
	"avionics engineer for [space_company]",
	"asteroid miner",
};

static char *time_off[] = {
	"time off",
	"leisure time",
	"spare time",
	"evenings",
	"weekends",
};

static char *did_something_innocuous[] = {
	"looked around",
	"twiddled [herop] thumbs",
	"shuffled [herop] feet",
	"pushed [herop] glasses up",
	"scratched [herop] head",
	"sighed wistfully",
	"took a deep breath",
	"lifted [herop] head",
	"sneezed",
	"looked up",
};

static char *character_introduction[] = {
	"[Hero] [HeroLastName] was a [heroprofession] from [space_locale]. "
	"[hero3] liked to drink a [spacedrink] in [herop] [time_off].",
	"[Hero] [HeroLastName] came from [space_locale]. [Hero] was a [heroprofession].",
	"[Hero] [HeroLastName] was born in [space_locale] but considered [heroself] to be from [space_locale]. [Hero] was a [heroprofession]. ",
	"[Hero] [HeroLastName] [did_something_innocuous]. [Hero] was a [heroprofession] headed for [space_locale].",
};

static char *gets_into[] = {
	"gets into",
	"climbs into",
	"hops into",
	"jumps into",
};

static char *land_vehicle[] = {
	"land speeder",
	"air car",
	"cargo hauler",
	"overland transport",
};

static char *begins_land_vehicle[] = {
	"fires up the engines",
	"heads out",
	"throttles up the engines",
	"engages the drive",
	"hits the throttle",
	"points it [towards] [herop] destination",
};

static char *land_vehicle_travel[] = {
	"[hero] [gets_into] a [land_vehicle] and [begins_land_vehicle].",
};

static char *animalback_travel[] = {
	"[hero] climbs onto the back of a [rideable_animal] and sets off",
};

static char *ambulating[] = {
	"walking",
	"running",
	"hiking",
	"walking at a brisk pace",
};

static char *ambulates[] = {
	"walks",
	"runs",
	"hikes",
	"walks at a brisk pace",
};

static char *towards[] = {
	"towards",
	"in the direction of",
	"for",
};

static char *ambulating_travel[] = {
	"[hero] begins [ambulating] [towards] [herop] destination",
	"[hero] [ambulates] [towards] [herop] destination",
	"[hero] sets off on foot [towards] [herop] destination",
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
	{ "herothinks", ARRAYSIZE(herothinks), herothinks },
	{ "heroisbored", ARRAYSIZE(heroisbored), heroisbored },
	{ "looks", ARRAYSIZE(looks), looks },
	{ "heroworksjob", ARRAYSIZE(heroworksjob), heroworksjob },
	{ "heropondersjob", ARRAYSIZE(heropondersjob), heropondersjob },
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
	{ "animalback_travel", ARRAYSIZE(animalback_travel), animalback_travel },
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
	{ "rideable_animal", ARRAYSIZE(rideable_animal), rideable_animal },
	{ "profession", ARRAYSIZE(profession), profession },
	{ "character_introduction", ARRAYSIZE(character_introduction), character_introduction },
	{ "time_off", ARRAYSIZE(time_off), time_off },
	{ "did_something_innocuous", ARRAYSIZE(did_something_innocuous), did_something_innocuous },
	{ "space_company", ARRAYSIZE(space_company), space_company },
	{ "herospaceshipthings", ARRAYSIZE(herospaceshipthings), herospaceshipthings },
	{ "spaceshipgauges", ARRAYSIZE(spaceshipgauges), spaceshipgauges },
	{ "spaceshipdash", ARRAYSIZE(spaceshipdash), spaceshipdash },
	{ "spaceshipsystem", ARRAYSIZE(spaceshipsystem), spaceshipsystem },
	{ "spacecraft", ARRAYSIZE(spacecraft), spacecraft },
	{ "boards", ARRAYSIZE(boards), boards },
	{ "take_off", ARRAYSIZE(take_off), take_off },
	{ "spaceship_travel_embark", ARRAYSIZE(spaceship_travel_embark), spaceship_travel_embark },
	{ "spaceship_travel_disembark", ARRAYSIZE(spaceship_travel_disembark), spaceship_travel_disembark },
	{ "disembarks", ARRAYSIZE(disembarks), disembarks },
	{ "gets_into", ARRAYSIZE(gets_into), gets_into },
	{ "land_vehicle", ARRAYSIZE(land_vehicle), land_vehicle },
	{ "land_vehicle_travel", ARRAYSIZE(land_vehicle_travel), land_vehicle_travel },
	{ "begins_land_vehicle", ARRAYSIZE(begins_land_vehicle), begins_land_vehicle },
	{ "towards", ARRAYSIZE(towards), towards },
	{ "ambulates", ARRAYSIZE(ambulates), ambulates },
	{ "ambulating", ARRAYSIZE(ambulating), ambulating },
	{ "ambulating_travel", ARRAYSIZE(ambulating_travel), ambulating_travel },
	{ "spaceship_location_name", ARRAYSIZE(spaceship_location_name), spaceship_location_name },
};

static char *fight_action1[] = {
	"lunged at",
	"swung at",
	"leaped on",
	"grappled with",
	"pushed",
	"moved [towards]",
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

static char *sat_at_the_bar[] = {
	"sat at the bar",
	"leaned on the bar",
	"slumped at the bar",
	"farted at the bar",
	"eyed the room with suspicion", 
	"listened to the music", 
	"sat at the bar, smoking", 
	"tried to get the bartender's attention", 
};

static char *bar_char[] = {
	"a [body_size] [planetary_origin] [alien_type] [drinking] a [spacedrink] [sat_at_the_bar]",
	"a [planetary_origin] [alien_type] with [alien_appendages] covered with [alien_skin] and [alien_eyes] [drinking] a [spacedrink] [sat_at_the_bar]",
	"[drinking] a [spacedrink], a [body_size] [alien_type] from [space_locale] [sat_at_the_bar]",
};

static char *spaceport_bar1[] = {
	"the dimly lit spaceport bar. As [p1p] eyes adjusted to the light, [p1] could make out "
	"a variety of characters seated at the bar. Closest [bar_char]. Next, [bar_char]. "
	"Finally, [bar_char]. A rough crowd.",
};

static char *spaceship_interior[] = {
	"{luxurious_spaceship_cabin}",
#if 0
	"{military_spaceship_cabin}",
	"{cargo_spaceship_cabin}",
	"{pirate_spaceship_cabin}",
#endif
};

static char *planetary_outdoor_location_name[] = {
	"the Antean desert",
	"the eastern part of the Nordan Mountains",
	"the jungles of Korboda",
	"a quiet, dusty street",
	"a busy street",
	"the shore of Lake Drogon",
	"the edge of the grass plains",
	"the edge of a small town",
	"the forest of Horgon trees",
	"the swamps of Torgo",
	"the junkyard",
	"a field of norc plants",
	"outside the gun shop",
	"outside the hangar",
	"outside the bar",
	"the street in front of the bar",
	"the governor's palace",
};

static char *planetary_indoor_location_name[] = {
	"the interior of a small, dingy apartment",
	"the local spaceship repair shop",
	"a show selling local fruits and vegetables",
	"the Lucky Spaceman Bar and Grill",
	"the local Blasters-R-US gun store",
	"Hanger 18",
	"a small hut",
	"a cave",
	"the castle of Thormo",
	"the fortress of Wandor",
	"the palace of Snubon",
	"the courtyard",
	"a small hotel room",
	"an ossio den",
	"the shrine of Tooboo",
	"the cemetery of Yono",
	"the temple of Gren",
	"the site of the wreck of the Kranos",
	"the edge of the Sea of Anger",
	"the edge of the lake of the Akorz",
	"the summit of Mount Norbit",
	"the base of Mount Ebla",
	"the head of the trail of Sentoria",
	"the edge of the city of Yanrovia",
	"[spaceport_bar1]",
};

static char *large_spaceport[] = {
	"the Trenolo Memorial Spaceport",
	"the Hogon Interplanetary Spaceport",
	"the Jerno Interplanetary Spaceport",
	"the Wollowella Intergalactic Spaceport",
	"the Jarboz-Newkron Pangalactic Spaceport",
	"the old Kradon Interplanetary Spaceport",
	"the bustling Oolonian Pan-Galactic Mega-Spaceport",
	"the Reeno-Jeekrano Interplanetary Spaceport",
	"the local planet-hopper spaceport",
	"the spaceport in Nollo",
	"the spaceport in Fallia",
	"the spaceport in Koznor",
};

static char *spaceport_location_name[] = {
	"[large_spaceport]",
};

static char *planetary_connection_via[] = {
	"[land_vehicle_travel]",
	"[ambulating_travel]",
	"[animalback_travel]",
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
	{ "sat_at_the_bar", ARRAYSIZE(sat_at_the_bar), sat_at_the_bar },
	{ "luxurious_spaceship_cabin", ARRAYSIZE(luxurious_spaceship_cabin), luxurious_spaceship_cabin },
	{ "planetary_outdoor_location_name", ARRAYSIZE(planetary_outdoor_location_name),
				planetary_outdoor_location_name},
	{ "planetary_indoor_location_name", ARRAYSIZE(planetary_indoor_location_name), planetary_indoor_location_name},
	{ "large_spaceport", ARRAYSIZE(large_spaceport), large_spaceport },
	{ "spaceport_location_name", ARRAYSIZE(spaceport_location_name), spaceport_location_name},
	{ "planetary_connection_via", ARRAYSIZE(planetary_connection_via), planetary_connection_via},
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
static char **macro_set_name = NULL;

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
					if (alt == NULL || strcmp(macro_set[i].m[j].alt[k], alt) == 0) {
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

void clear_macro(char *setname, char *name)
{
	remove_macro(setname, name, NULL);
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
