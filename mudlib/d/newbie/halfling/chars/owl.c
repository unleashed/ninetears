
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("owl");
set_short("Owl");
set_main_plural("owls");
add_plural("owls");
set_long("You gasp as you suddenly notice a huge owl before you.  "
   "The only reason you even saw it amongst the dark trees is "
"because it opened its glowing yellow eyes.  The way it looks "
   "at you puts you on edge.\n");

set_random_stats(4,8);
set_level(2+random(2));
set_gender(2);
}
