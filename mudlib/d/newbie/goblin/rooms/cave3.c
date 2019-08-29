// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Caves");
   set_light(20);
   set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Gloomy Caves\n\n"
	 "     You can see exits out to the real world to the south, "
    "southeast, and southwest. "
    "Time to go and seek your fortune and fame, hopefully you will not have a "
   "short career.\n\n");

// Items....
add_exit("south","/d/mm/Cities/caldera/city_roads/r18.c","path");

// Exits....
} /*setup() */

