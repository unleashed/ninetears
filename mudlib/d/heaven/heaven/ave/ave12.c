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
" the west of you lies "+ IM12A + 
", while to the east of you lies "+ IM12B +".\n"+
"A statue sits here.  It is of a mighty dragon.\n");
set_short("Immortal square");
add_exit("north",ROOM+"ave11","road");
add_exit("west",IR12A,"door");
add_exit("east",ROOM+"ave9","road");
add_exit("south",ROOM+"ave13","road");
set_light(100);
add_item(({"dragon","statue"}),"This is a statue of Spawn, the "+
"hell dragon.  She is the hunter, never the hunted.  She is the"+
" Hunter of the Immortals.  Sent to retrieve the worst of sinners."+
"  There is a plaque on the statue that says: Immortal Challenge.\n");

}      

