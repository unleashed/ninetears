
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("wizard");
set_short("Hedge Wizard");
set_main_plural("hedge wizards");
add_plural("wizards");
set_long("This is a small evil wizard.  After failing to learn the "
"stronger and finer points of magic, he was forced to live "
 "in the wild and kill others to survive.  He is small and very "
   "dirty, and the look in its eyes tells you that you are its "
   "next victim.\n");

set_random_stats(5,12);
set_level(4+random(4));
set_gender(1);
add_clone("/baseobs/armours/leather.c",1);
set_race_ob("/std/races/halfling.c");
adjust_money(1+random(5), "silver");
}
