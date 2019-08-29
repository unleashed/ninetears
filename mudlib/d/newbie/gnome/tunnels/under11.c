inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     You can tell that this part of the tunnel has been mined " 
   "quite a bit more than the last one had been.  The walls are "
   "almost satiny to the touch due to their "
    "smoothness.  Again this area seems to be very neat, and does "
    "not look as if it were hastily abandoned. "
   "You can continue on to your southeast or you can  go "
   "explore the caverns to your northeast.  To go back head northwest.\n\n");
add_item(({"walls","ceiling","floor","wall"}),"You look at the "
   "walls and floors surrounding you and boggle at how "
   "smooth and soft they are for rocks.  The scant light reflects "
   "off the surface of the walls and ceiling, thus seeming to "
   "amplify it.\n\n");
add_exit("northwest",UNDER +"under04","path");
add_exit("northeast",UNDER +"under05","path");
add_exit("southeast",UNDER +"under16","path");
add_clone(CHAR+"bat.c", 1);
}
