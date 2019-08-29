
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("half-orc");
set_short("half-orc");
add_alias("half-orc");
add_plural("half-orcs");
add_plural("half-orcs");
set_main_plural("half-orcs");
set_long("This is an ugly creature.  He looks vaguely "
   "human, and yet it is too ugly and evil to be even that.  "
"He seems to prefer to hide in the shadows, and look for "
   "easy prey.\n\n");
 
 set_random_stats(5,18);
 set_str(15);
 set_con(15);
 set_race_ob("/std/races/half-orc.c");
 set_level(4+random(3));
set_gender(2);
set_guild("fighter");

adjust_money(4+random(9),"silver");

 add_clone("/baseobs/weapons/short_sword.c",1);
 add_clone("/baseobs/armours/padded.c",1);
 this_object()->init_equip();
}
