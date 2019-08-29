#include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELDCITY,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand in the City of"
" the Immortals.  You stare in awe at the wondrous building around"
" you.  You feel the magic in the air, and feel at peace here. To"
" the west of you lies "+ IM4A + 
", while to the east of you lies "+ IM4B +".\n");
set_short("Immortal Avenue");
add_exit("north",ROOM+"ave3","road");
add_exit("south",ROOM+"ave5","road");
add_exit("west",IR4A,"door");
add_exit("east",IR4B,"door");
set_light(100);
}      

