
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("sprite");
set_short("Sprite");
set_long("This is a small winged creature.  She has a vaguely human "
"shape, but is a good deal smaller and she has fragile gossamer wings "
"on her back.  Obviously, she makes her home here in the clearing.  \n");
 
set_random_stats(3,10);
set_level(3);
set_gender(2);
 add_clone("/baseobs/weapons/knife.c",1);
 this_object()->init_equip();
  adjust_money(5+random(15),"copper");
}
