
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("brownie");
set_short("Brownie");
set_long("This is a small mischievious creature. He is rather "
   "short and has small pointed ears.  These creatures take "
   "great delight in "
   "playing mean pranks on other people, and generally torturing "
"them.  He laughs wickedly at you, and you can tell he is "
   "thinking up evil things to do to you.\n\n");
 
set_random_stats(4,14);
set_str(17);
 set_level(4+random(2));
set_gender(1);

 adjust_money(5+random(10),"copper");
 add_clone("/baseobs/weapons/knife.c",1);
 add_clone("/baseobs/armours/cloak.c",1);
 this_object()->init_equip();
}
