
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("buzzard");
set_short("Buzzard");
set_main_plural("buzzards");
add_plural("buzzards");
set_long("This is a huge black buzzard, and the fact that it is "
"here looking healthy worries you.  It is "
   "obvious that it stays well fed from its diet of dead flesh.\n");

set_race("buzzard");
set_random_stats(5,9);
set_level(1+random(3));
set_gender(1);
}
