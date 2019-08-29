inherit "/std/basic/print_object";
/*
 * This is called off of the monster to set up a race and
 * proffesion...  Race should be first then proffesion..
 */
#include "race.h"

mapping races,
        guilds;

void create() {
  races = ([
    0          : "/std/races/unknown", /* first the null race */
    "troll"    : "/std/races/troll",
    "pollo"  : "/std/races/chicken",
    "pato"     : "/std/races/duck",
    "pez"     : "/std/races/fish",
    "humano"    : "/std/races/human",
    "elfo"      : "/std/races/elf",
    "medio-elfo" : "/std/races/half-elf",
    "halfling" : "/std/races/halfling",
    "drow"     : "/std/races/drow",
    "orco"      : "/std/races/orc",
    "enano"    : "/std/races/dwarf",
    "guppy"    : "/std/races/guppy",
    "pinguino"  : "/std/races/penguin",
    "goblin"   : "/std/races/goblin",
    "medio-orco" : "/std/races/half-orc",
    "ent"      : "/std/races/ent.c",
    "hombre-lagarto":"/std/races/lizard-man",
  ]);
  guilds = ([
    0              : "/std/guild",
    "fighter"      : "/d/gremios/guerreros/fighter",
    "warrior"      : "/d/gremios/warrior",
    "cleric"       : "/d/gremios/cleric",
    "priest"       : "/d/gremios/cleric",
    "tymora"       : "/d/gremios/priests/tymora",
    "tempus"       : "/d/gremios/priests/tempus",
    "lathander"    : "/d/gremios/priests/lathander",
/*    "lolth"        : "/d/gremios/priests/lolth", */
    "witch"        : "/d/gremios/magos/witch",
    "wizard"       : "/d/gremios/magos/general_wizard",
    "mage"         : "/d/gremios/mage",
/*    "necromancer"  : "/d/gremios/magos/necromancer", */
    "thief"        : "/d/gremios/picaros/thief",
    "rogue"        : "/d/gremios/rogue",
    "assassin"     : "/d/gremios/picaros/assassin",
  ]);
} /* create() */

int query_valid_race(string race) {
  return races[race];
} /* query_valid_race() */

int query_guild_path(string guild) {
  return guilds[guild];
} /* query_guild_path() */

int add_race(string name, mixed ob) {
  if (races[name]) return 0;
  races[name] = ob;
  return 1;
} /* add_race() */

int remove_race(string name) 
  {
  if (!races[name]) return 0;
  races[name] = 0;
  return 1;
} /* remove_race() */

mapping query_races() { return races; }

int add_guild(string name, mixed ob) 
  {
  if (guilds[name]) return 0;
  guilds[name] = ob;
  return 1;
} /* add_guild() */

int remove_guild(string name) {
  if (!guilds[name]) return 0;
  guilds[name] = 0;
  return 1;
} /* remove_guild() */

mapping query_guilds() { return guilds; }

void monster_heart_beat(string race, string pclass, mixed race_ob, mixed class_ob) {
  race_ob->player_heart_beat(race);
  class_ob->player_heart_beat(pclass);
} /* monster_heart_beat() */

int query_limbs()
  {
  return 2;
} /* int query_limbs */
