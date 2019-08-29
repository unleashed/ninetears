// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  gloomy Tunnels");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
      "     You are in a tunnel that comes off from the river. To the "
      "south you see an underground river. You can here the crashing of "
      "water from both the north and south. To the north you see a pile "
      "of rubble, it may be a cave in.\n\n");
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
    add_item("rubble","It looks like a small cave in. You hope you "
      "can get across it.\n");

    // Items....

    add_exit("north", ROOM"ngob21.c","path");
    // Exits....

    add_clone(CHAR+"drole.c",2);
} /*setup() */

void init() {
    add_action("listen_water","listen");
    add_action("wade_south","wade");
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

int wade_south(string str) {
    if(str == "south" || str =="s" || "river")
    {
        write("You wade into the river.\n");
        say(this_player()->query_cap_name()+" wades south into the river.\n");
        this_player()->move(ROOM+"ngob17.c");
        say(this_player()->query_cap_name()+" wades into the river from the north.\n");
        this_player()->look_me();
        return 1;
    }
}
