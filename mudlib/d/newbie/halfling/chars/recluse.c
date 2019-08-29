
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("recluse");
set_short("Recluse");
set_main_plural("recluses");
add_plural("recluses");
set_long("Before you stands a very reclusive halfling.  He is "
   "whispered that long ago he used to be a thief, but now "
"prefers the quiet solitude that his home affords him.  "
   "He is shrouded in mystery prefering the name Recluse rather "
   "than giving you his real name.  Despite this reclusiveness "
    "it has been rumored that he can teach young halflings a "
   "thing or two.\n\n");
 
 set_race_ob("/std/races/halfling.c");
set_random_stats(5,13);
set_level(3+random(3));
set_gender(1);
set_guild("fighter");
}
