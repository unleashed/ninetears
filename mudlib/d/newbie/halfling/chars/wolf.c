
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("wolf");
set_short("Wolf");
set_main_plural("wolves");
add_plural("wolves");
set_long("Suddenly a huge wolf stands before you.  You could see the "
   "muscles under its fur ripple as it lept from the surrounding "
   "foliage.  It considers you with bright silver eyes, as it "
   "bares his teeth preparing to attack you.\n");
 
set_random_stats(5,12);
 set_str(13);
set_level(2+random(3));
set_gender(1);
set_race("wolf");
}
