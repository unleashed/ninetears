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
      "     You are standing underneath a natural bridge. The water "
      "seems to rushing past you very strongly, flowing to the west. "
      "There is a very loud rumbling sound coming from the west. "
      "The air here is very damp and misty. You can go to the west or east.\n\n");
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
    add_item("bridge","This is a natural stone bridge. To bad you can't get "
      "up there so you could dry off.\n");

    // Items....

    add_exit("west", ROOM+"ngob23.c","path");
    add_exit("east", ROOM+"ngob24.c","path");
    // Exits....
} /*setup() */

void init() {
    add_action("listen_rumbling","listen");
    ::init();
}
int listen_rumbling(string str) {
    if(str=="rumbling") {
        write("The rumbling is so loud that you have to hold your ears "
          "to keep from going deaf. It kinda of sounds like water crashing "
          "down.\n");
        tell_room(ENV(TP),CNAME + " holds his ears as he listens "
          "to the rumbling sound.\n", (TP));
        return 1;
    }
}
