#include "path.h"
inherit CASTLE+"baseroom3.c";
 void setup() {
set_short("Realm of the Orc:  Village Center");
set_light(40);
   set_long("\n   Realm of the Orc:  Village Center.\n\n"
            "     This is the center of a small village.  There is "
            "not very much going on here, in fact, you can see "
            "no one moving about at all.  You can hear the sounds "
            "of a smithy to the south and can see what looks like a "
            "tavern down the road to the west.  Going east leads out "
            "of town along a path that leads upward into the mountain.  "
            "\n\n");


add_property("no_undead",1);
add_exit("south",TOWN +"town09.c","road");
add_exit("east",TOWN +"town06.c","road");
add_exit("west",TOWN +"town04.c","road");
add_exit("north",TOWN+"town02.c","door");
}
 
