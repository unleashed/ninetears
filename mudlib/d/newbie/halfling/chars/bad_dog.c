
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("dog");
set_short("Rabid Dog");
set_long("This is a snarling, vicious, rabid dog.  Foam drips from his "
"mouth as he growls viciously at you.  He is crouched down and "
   "ready to attack you.\n");
 
set_random_stats(3,6);
set_level(3+random(3));
set_gender(1);
}
