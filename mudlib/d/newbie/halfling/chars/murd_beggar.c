
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("beggar");
set_short("Murderous Beggar");
 set_long("This is a murderous beggar.  He was once an ordinary "
"citizen, but having fallen upon hard times, now kills others "
   "if they wont hand over their money.\n");
 
set_dex(10);
set_random_stats(3,10);
set_level(6);
 add_clone("/baseobs/weapons/dagger.c",1);
 this_object()->init_equip();
set_gender(1);
  adjust_money(5+random(3),"copper");
}
