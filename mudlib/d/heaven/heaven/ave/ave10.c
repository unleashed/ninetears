#include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELDCITY,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand in the City of"+
" the Immortals.  You stare in awe at the wondrous buildings around"+
" you.  You feel the magic in the air, and feel at peace here. To"+
" the west of you lies "+ IM10A + 
", while to the east of you lies "+ IM10B +".\n"+
"To the south of you is a window into the universe. From it you"+
" can see Magisk Jord from the heavens.  You cannot make out any"+
" details out, but it is very pretty.\n");
set_short("Immortal square");
add_exit("north",ROOM+"ave9","road");
add_exit("west",ROOM+"ave13","road");
add_exit("east",ROOM+"ave16","road");
set_light(100);
}      

