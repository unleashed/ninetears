// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Edge of Lake");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  Edge of Lake\n\n"
      "     You have come to the edge of a large underground lake "
      "There are many goblin footprints near the shore. "
      " You should be able to wade into the lake to the west it does not look very "
      "deep.\n\n");
    add_property("no_undead",1);
    add_item(({"feet"}),
      "They appear to be pretty fresh you could probly cook and eat them.\n");
    add_item(({"footprints"}),
      "Uh Oh looks like you were mistaken not only are they goblin"
      " footprints, they seem to still have the goblin feet in them. "
      "It appears that they were bitten off just above the ankles.\n");
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

    add_exit("east",ROOM+"ngob35.c","path");
    // Exits....

    add_clone(CHAR+"drole.c",1);
} /*setup() */

void init() {
    add_action("wade_lake","wade");
    ::init();
}
int wade_lake(string str) {
    if(str == "northwest" || str =="nw" || "lake")
    {
        write("You wade into the lake.\n");
        say(this_player()->query_cap_name()+" wades northwest into the lake.\n");
        this_player()->move(ROOM+"ngob30.c");
        say(this_player()->query_cap_name()+" wades into the lake from the southeast.\n");
        this_player()->look_me();
        return 1;
    }
}
