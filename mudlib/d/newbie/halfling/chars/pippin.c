
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("pippin");
set_short("Pippin");
set_long("This is one of the Pippin twins.  You used to play with them as children, "
"but have long since outgrown their childish games.  While remembering all this, "
"it occurs to you that you owe them for all the times they beat you up as a child.  \n");
add_clone(WEAPONS+"short_sword.c",1);
 
 set_race_ob("/std/races/halfling.c");
set_random_stats(3,10);
set_level(3);
set_gender(1);
set_guild("fighter");
}
