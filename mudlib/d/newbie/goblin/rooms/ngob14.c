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
      "     You are in a dark, damp passage. The walls here are covered "
      "in moss and fungus. To the north you hear running water,"
      "it may be a underground river. This tunnel continues north and south." 
      "You can tell that these tunnels are not traveled much by all the dust "
      "on the ground.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item(({"ground","floor"}),"The ground is covered in dust, with "
      "some foot prints occasionally being seen.\n");
    add_item("dust","This dust has been here awhile.\n");
    add_item(({"foot prints","prints"}),"You see some foot prints but "
      "they have been smeared in too much to tell where they go.\n");

    // Items....

    add_exit("north","/d/newbie/goblin/rooms/ngob15.c","path");
    add_exit("southeast","/d/newbie/goblin/rooms/ngob10.c","path");
    // Exits....

    add_clone(CHAR+"drole.c",2);
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
