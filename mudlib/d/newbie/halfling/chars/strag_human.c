
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("human");
set_short("Straggling Human");
set_long("At first glance, this poor human wears a look of utter "
"hopelessness on his face.  He appears to be very lost, but as he "
   "notices you standing nearby the look of hopelessness turns to "
 "pure hate.  He mutters a curse and draws a knife from under his tunic, gesturing "
"to you with it, and then to his throat.  \n");

set_random_stats(3,10);
set_level(3);
set_gender(1);
 add_clone("/baseobs/weapons/knife.c",1);
 this_object()->init_equip();
  adjust_money(10+random(3),"copper");
}
