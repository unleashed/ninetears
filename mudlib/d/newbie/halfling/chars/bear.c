
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("bear");
set_short("Bear");
set_long("Before you stands a huge angry bear.  You can see its giant "
   "muscles ripple beneath its fur coat, and it stares intently "
   "at you with glowing red eyes.  It grolws low in its throat.\n");
 
set_random_stats(3,10);
 set_str(16);
 set_level(3+random(2));
set_gender(1);
}
