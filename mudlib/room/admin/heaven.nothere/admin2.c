#define IMM1 " "
#define IMM2 " "
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELD,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("This is a black marble hallway.  Power flows through"
" the very"
" that serves as the walls of this halway.  You are afraid that"
" the power"
" will someday burst out of the crystal and destroy this"
" wonderous place."
"  A door lies to your north, and to your south.  A golden"
" plaque on the "
"northern door reads: Mail Control.  A identical plaque"
"on the southern door reads: Quest regulation.\n");
set_short("admin hallway 2");
add_exit("north",ADMIN+"mail_room","door");
add_exit("south",ADMIN+"quest_room","door");
add_exit("east",ROOM+"admin3","road");
add_exit("west",ROOM+"admin1","road");
add_item("carpet","There is none.");
add_item("plaque","It is made of gold and magically sealed"
" to the door.\n");
set_light(100);
}      

