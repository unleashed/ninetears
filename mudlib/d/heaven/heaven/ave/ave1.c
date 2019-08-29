#include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELD,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand south"+
" of the palace, and too the west of you lies "+ IM1A +
", while to the east of you lies "+ IM1B +".\n");
set_short("Immortal Avenue");
add_exit("north",ROOM+"palacegates","road");
add_exit("south",ROOM+"ave2","road");
#add_exit("west",IR1A,"door");
#add_exit("east",IR1B,"door");
set_light(100);
}      
