// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  River");
    set_light(20);
    set_zone("newbie_river");
    set_long("\nRealm of the Goblin:  River\n\n"
      "     You are wading in a shallow river, it is so cold that "
      "you think your poor feet are about to freeze solid. "
      "The river starts to get wider here and begins to get a little "
      "deeper. To the northeast you see a large cavern, an underground "
      "lake seems to fill most of it.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item("river","This river doesn't look to deep as far as you "
      "can tell, maybe about two feet deep. You see some blind fish swimming "
      "in it occassionally.\n");
    add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
      "they look quite tasty.\n");
    add_item(({"feet","foot"}),"Your feet are starting to turn purple.");
    add_item(({"large cavern","northeast","lake"}),"You see a really large "
      "lake to the northeast, you hope it's not dangerous.\n");

    // Items....

    add_exit("southwest", ROOM+"ngob18.c","path");
    add_exit("northeast", ROOM+"ngob30.c","path");
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
