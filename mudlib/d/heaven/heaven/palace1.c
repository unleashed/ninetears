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
set_long("This is the palace grand hall.  It is richly furnished, and has plush"+
" carpeting.  The walls stand about 20 feet high and are made of pure silver."+
"  Relaxing elven music plays from a uknown source, and the temperature "+
"seems to be just right.  There is probably not more of a relaxing atmosphere"+
" in the universe.  The grand hall continues to the north.\n");
set_short("Grand hall -South");
add_exit("north",ROOM+"palace2","road");
add_exit("south",ROOM+"entry","portal");
add_item("carpet","It is red and very thick.");
set_light(100);
}


