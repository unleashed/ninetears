#include "path.h"
inherit CASTLE+"baseroom3.c";
void setup() {
set_short("Realm of the Orc:  Small Road");
set_light(40);
   set_long("\n   Realm of the Orc:  Small Road.\n\n"
            "     This is a small road that leads into the village.  "
            "From here, the village seems to be deserted and there "
            "aren't many buildings here.  What is here is to the "
            "west and the path going east leads up to the mountain.  "
"You hear some chanting coming from the south.\n\n");
add_sound("chanting", " You hear the sounds of several orcs chanting, but as if their singing was not bad enough, screams of pain add their un-harmonious blend to it.\n\n");

add_exit("northeast",CASTLE +"orc41.c","path");
add_exit("west",TOWN +"town05.c","path");
add_exit("south", TOWN +"town03.c","path");
}

