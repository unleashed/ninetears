// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Gloomy Tunnels");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
      "     You are standing in a cavern that is very humid and misty. "
      "The walls are dripping with water and have lots of fungus growing "
      "on them. To the south you see a natural stone bridge. "
      "there are tunnels leading off to the east and north.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");

    // Items....

    add_exit("north", ROOM"ngob26.c","path");
    add_exit("south", ROOM "ngob22.c","path");
    add_exit("east", ROOM "ngob27.c","path");
    // Exits....
} /*setup() */

void init() {
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
