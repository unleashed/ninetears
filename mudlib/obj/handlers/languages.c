#include "language.h"
/*
 * The language handler.  This will keep track of the info on languages
 * Each language can be a written language a spoken language and have
 * a garble object.
 *
 * The function garble_say, garble_tell, garble_shout and
 * garble_written shoud be defined on the garbling object.
 * They should return the entire string to print.  So if the
 * routine returns 0 nothing is printed.
 */

mapping languages;

void create() {
  languages = 
  ([
    "common" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/common", 10 }),
    "comun" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/common", 10 }),
    "mimica de ladron" : ({ L_SPOKEN, "/std/languages/cant", 100 }),
    "thieve's cant" : ({ L_SPOKEN, "/std/languages/cant", 100 }),
    "grunt" : ({ L_SPOKEN, "/std/languages/grunt", 100 }),
    "wizard spells" : ({ L_WRITTEN|L_MAGIC|L_SIZED,
                       "/std/languages/wizard_lang", 100 }),
    "elfo" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/elf", 10 }),
    "elf" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/elf", 10 }),
//    "chiquitistan" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/chiquitistan", 10 }),
    "drow" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/drow", 10 }),
    "enano" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/dwarf",10}),
    "dwarf" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/dwarf",10}),
   "duergar" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/duergar",10}),
    "halfling" : ({L_SPOKEN|L_WRITTEN|L_DISTANCE,"/std/languages/halfling",10}),
    "gnomo" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/gnome", 10 }),
    "gnome" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/gnome", 10 }),
    "goblin" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/goblin", 10 }),
    "orco" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/orc", 10 }),
    "orc" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/orc", 10 }),
    "frog" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/frog", 10 }),
    "newt" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/newt", 10 }),
    "varniad" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/varniad", 10 }),
    "ilythiiri" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/ilythiiri", 10 }),
    "troll" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/troll", 10 }),
    "guppy" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/guppy", 10 }),
    "kender" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/kender",10}),
    "quack" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, "/std/languages/quack", 10 }),
    "werewolf" : ({ L_SPOKEN|L_DISTANCE,"/std/languages/werewolf",10 }),
    "barbarian" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, 
                     "/std/languages/barbarian", 10 }),
    "hombre-lagarto" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, 
                     "/std/languages/lizard-man", 10 }),
    "lizard-man" : ({ L_SPOKEN|L_WRITTEN|L_DISTANCE, 
                     "/std/languages/lizard-man", 10 }),
    "drizz" : ({ L_SPOKEN, "/std/languages/drizz", 100 }),
    "gobbledegook" : ({ L_SPOKEN|L_DISTANCE, "/std/languages/gobbledegook", 10 }),
    "arf" : ({ L_SPOKEN|L_DISTANCE, "/std/languages/arf", 10 }),
    "bork" : ({ L_SPOKEN|L_DISTANCE, "/std/languages/bork", 10 }),
    "giant" : ({ L_SPOKEN|L_DISTANCE, "/std/languages/giant", 10 }),
    "skaven" : ({ L_SPOKEN|L_DISTANCE, "/std/languages/skaven", 10}),
  ]);
} /* create() */

int query_language_spoken(string str) {
  if (!languages[str])
    return 0;
  return languages[str][0]&L_SPOKEN;
} /* query_language_spoken() */

int query_language_written(string str) {
  if (!languages[str])
    return 0;
  return languages[str][0]&L_WRITTEN;
} /* query_language_written() */

/* Distance languages can be used with tell and shout */
int query_language_distance(string str) {
  if (!languages[str])
    return 0;
  return languages[str][0]&L_DISTANCE;
} /* query_language_distance() */

/*
 * A magical langage gets a function called on it's object whenever it
 * is read even if the person knows the language.  It is also the language
 * spells are written in.
 *
 */
int query_language_magic(string str) {
  if (!languages[str])
    return 0;
  return languages[str][0]&L_MAGIC;
} /* query_language_magic() */

int query_language_size(string str) {
  if (!languages[str])
    return 0;
  return languages[str][2];
} /* query_language_size() */

/* This is called to resize the text if it doesnt fit... */
mixed squidge_text(string lang, mixed str, int size) {
  if (!languages[lang])
    return 0; /* Don't add it... */
  if (!(languages[lang][0]&L_MAGIC))
    return str[0..(size/languages[lang][2])];
  return (mixed)languages[lang][1]->squidge_text(str, size);
} /* squish_text() */

int add_language(string name, int flags, mixed ob, int size) {
  languages[name] = ({ flags, ob, size });
} /* add_language() */

int query_flags(string name) {
  if (!languages[name])
    return 0;
  return languages[name][0];
} /* query_flags() */

mixed query_garble_object(string name) {
  if (!languages[name])
    return 0;
  return languages[name][1];
} /* query_garble_object() */

string *query_languages() {
  return m_indices(languages);
} /* query_languages() */

int test_language(string str) {
  return pointerp(languages[str]);
} /* test_language() */
