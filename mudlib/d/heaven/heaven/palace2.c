#define IMM1 " "
#define IMM2 " "
#include "path.h"
inherit"/std/room.c";

void init() {
/*
shield_it(SHIELD,"/d/ss/daggerford/ladyluck");
*/
::init();
}

void setup() {
set_long("This is the northern end of the palace grand hall.  It is bare"+
" except"+
" for a statue in the center of the room.  The enchanting elven music flows "+
"throughout this hallway as well, easing your soul and mind.  There are "+
"doors"+
" to the north, east, and west of you.  The grand hall continues to the"+
" south.\n");
set_short("grand hall - north");
//add_exit("north",ROOM+"ntower1","door");
add_exit("south",ROOM+"palace1","road");
//add_exit("east",ROOM+"admin1","door");
//add_exit("west",ROOM+"dining","door");
add_item("carpet","It is red and very thick.");
add_item("statue","It is a statue depicting three dragons.  There is "+
"a large white"+
" dragon, a large black dragon, and a large red dragon.  They are"+
" intertwined "+
"in a intricate dance of fate.  It seems the as if the dragons writhe"+
" slightly.\n");
set_light(100);
}      

