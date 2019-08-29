#include "immortals.h"
#include "path.h"
inherit"/std/room.c";

void init() {
shield_it(SHIELDCITY,"/d/ss/daggerford/ladyluck");
::init();
}

void setup() {
set_long("You are on Immortal avenue.  You stand in the City of"
" the Immortals.  You stare in awe at the wondrous buildings around"
" you.  You feel the magic in the air, and feel at peace here. To"
" the west of you lies "+ IM15A + 
", while to the east of you lies "+ IM15B +".\n"
"A statue sits here.  It is of a fiery bird.\n");
set_short("Immortal square");
add_exit("north",ROOM+"ave14","road");
add_exit("east",IR15A,"door");
add_exit("west",ROOM+"ave9","road");
add_exit("south",ROOM+"ave16","road");
set_light(100);
add_item(({"dragon","statue"}),"This is a statue of the Phoenix, the "
"protector.  She is the protector of the Realms.  She is the"
" adviser of the Immortals.  Summoned only upon armageddon."
"  There is a plaque on the statue that says: Immortal Challenge.\n");

}      

