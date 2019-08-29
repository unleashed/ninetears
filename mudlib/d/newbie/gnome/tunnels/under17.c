inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1); 
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     This area of the tunnel appears as if it was formed when an "
"area caved in.  The walls are of lose dirt and appear as if they could "
"give way at any moment.  To your east the walls seem to be a bit "
"sturdier, but that is due to the fact that water has turned the "
"dirt to clay. To your north and northwest, however, the walls appear "
"quite dry.\n\n");
add_item(({"wall","walls","floor","ceiling"}),"You try not to look too "
"close because you are afraid that the walls and ceiling might cave in at your slightest "
"touch.  The dirt here is barely held together by what moistre there is in "
"the room turning the dirt to clay.\n\n");
add_exit("north",UNDER +"under13","path");
add_exit("east",UNDER +"under18","path");
add_exit("northwest",UNDER +"under12","path");
add_clone(CHAR+"bat.c", 1);
}
