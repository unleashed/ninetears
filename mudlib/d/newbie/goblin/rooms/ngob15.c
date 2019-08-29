// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  River Bank");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  River Bank\n\n"
      "     You are standing on the edge of an underground river. "
      "It doesn't seem too have a strong current and you might "
      "be able to wade in it. To the south you see a tunnel."
      "To north is the river.\n\n");
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
    add_item("river","This river doesn't look to deep as far as you "
      "can tell, maybe about two feet deep. You see some blind fish swimming "
      "in it occassionally. You could probably see more if you waded into the "
      "river.\n");
    add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
      "they look quite tasty.\n");

    // Items....

    add_exit("south",ROOM+"ngob14.c","path");
    // Exits....
} /*setup() */

void init() {
    add_action("listen_water","listen");
    add_action("wade_north","wade");
    ::init();
}
int listen_water(string str) {
    write("You hear the sound of water running, it "
      "sounds quite relaxing.\n");
    tell_room(ENV(TP),CNAME + " seems to relax listening to the sounds "
      "of the water.\n", (TP));
    return 1;
}
int wade_north(string str) {
    if(str == "north" || str =="n" || "river")
    {
        write("You wade into the river.\n");
        say(this_player()->query_cap_name()+" wades north into the river.\n");
        this_player()->move(ROOM+"ngob16.c");
        say(this_player()->query_cap_name()+" wades into the river from the south.\n");
        this_player()->look_me();
        return 1;
    }
}
