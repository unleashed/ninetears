// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Unstable Bridge");
   set_light(20);
   set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Unstable Bridge\n\n"
	 "     You are standing on a natural stone bridge that crosses "
 "an underground river. The air here is misted with water vapors. "
 "You hear the rumbling of a water fall in the distance. "
 "To the north you see another tunnel, to the "
"south the tunnel looks to be partially caved in.\n\n");
add_property("no_undead",1);
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item(({"ground","bridge"}),"This is a stone bridge, it appears to  "
  "be a natural rock formation.\n");
add_item("river","The river seems to only be about 10 feet down. "
 "It runs from the east to the west, with a water fall being "
 "to the west. You may be able to jump down to the river.\n");

// Items....

add_exit("north", ROOM "ngob25.c","path");
add_exit("south", ROOM "ngob21.c","path");
// Exits....
} /*setup() */

void init() {
add_action("do_jump","jump");
add_action("listen_water","listen");
::init();
}
int listen_water(string str) {
if(str=="water") {
write("You hear the sound of water running, it "
"sounds quite relaxing.\n");
tell_room(ENV(TP),CNAME + " seems to relax listening to the sounds "
"of the water.\n", (TP));
return 1;
}
}
int do_jump(string str) {
if (!str)
{
  write("\nThere is gravity in this room, you must jump in a direction.\n");
   return 1;
}
else
{
if(str == "down" || str == "d")
{
write("\nYou hold your nose and breath and leap off the bridge.\n\n");
say(this_player()->query_cap_name()+" leaps off the bridge. "
 "\n\n");
this_player()->move(ROOM+ "ngob22a.c");
 write("With a splash you land in the river.\n");
say(this_player()->query_cap_name()+" drops out of the sky and lands "
  "in the river beside you.\n");
this_player()->look_me();
}
else
write("That type of jump would only get you in to trouble.\n");
return 1;
}
}
