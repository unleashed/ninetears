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
" the west of you lies "+ IM16A + 
", while to the south of you lies "+ IM16B +".\n");
set_short("Immortal square");
add_exit("north",ROOM+"ave15","road");
add_exit("east",IR13B,"door");
add_exit("south",IR13A,"door");
add_exit("east",ROOM+"ave10","road");
set_light(100);
}      

