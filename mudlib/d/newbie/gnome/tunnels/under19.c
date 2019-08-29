inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1); 
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     Some of the stalagtites and stalagmites have actually "
   "joined eachother now.  You see several of these columns around "
   "the cave, although they do not look very strong.  To the "
   "southwest you think you can see the point at which the stream "
   "ends. Your curiosity drives you in that direction versus going "
   "back to the northwest or the northeast.\n\n");
add_exit("southwest",UNDER +"under20","path");
add_exit("northwest",UNDER +"under14","path");
add_exit("northeast",UNDER +"under15","path");
add_clone(CHAR+"bat.c", 1);
}
