inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("Realm of the Gnome:  Macedonian Tunnel\n\n"
	 "     You can still hear the gurgling sound of the stream "
  "from behind you, but you notice that this part of the tunnel "
   "seems much dryer and a bit warmer.  You wonder if maybe the "
   "newbie/gnomes used to either live in this part of the tunnel, or if "
   "they just used it to take a break and dry out from working in "
   "the damper areas of the caves. You can head back to the east and "
   "to the stream or you can continue on to your south or your "
   "southwest.\n\n");
add_item(({"walls","wall","floor","ceiling"}),"The floors and walls "
   "seem to consist of dry packed earth. \n\n");
add_exit("south",UNDER +"under13","path");
add_exit("east",UNDER +"under07","path");
add_exit("southwest",UNDER +"under12","path");
add_clone(CHAR +"bat.c", 1);
}
