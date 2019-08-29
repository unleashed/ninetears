#define IMM1 " "
#define IMM2 " "
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELD,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("This the base of the Tower of Neutrality.  There "
"is a door to "
"the north and a stairway leads upwards.  The door to the north shifts"
" into a new form each time you look at it.  Even you can feel"
" the power"
" that radiates from the area beyond.  It is as if a purity"
" of magic makes"
" up the entire door.  You hesitate to follow that path.\n");
set_short("base of Tower of Neutrality");
add_exit("north","/w/devoe/workroom.c","door");
add_exit("south",ROOM+"palace2","road");
add_exit("up",ROOM+"/w/bivins","door");
add_item("carpet","It is red and very thick.");
add_item("door","It is made of pure magic.");
set_light(100);
}      

