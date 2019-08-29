#include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shiel_it(SHIELDCITY, "/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand in the City of"
" the Immortals.  You stare in awe at the wondrous building around"
" you.  You feel the magic in the air, and feel at peace here. To"
" the west of you lies "+ IM7A + 
", while to the east of you lies "+ IM7B +".  To the south of you"
" lies a square.  In the center of the square lies three statues.\n");
set_short("Immortal Avenue");
add_exit("north",ROOM+"ave6","road");
add_exit("south",ROOM+"ave8","road");
add_exit("west",IR7A,"door");
add_exit("east",IR7B,"door");
set_light(100);
}      

