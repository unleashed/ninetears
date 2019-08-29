// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Underground Waterfall");
    set_light(20);
    set_zone("newbie_river");
    set_long("\nRealm of the Goblin:  Undergroun Waterfall\n\n"
      "     You are standing on the edge of a waterfall. "
      "It is very loud here, the water fall is almost deafening. "
      "You see a natural bridge of some sort to the east. "
      "The current here is so strong it seems to be pulling you to the "
      "west. You probably shouldn't stay here to long.\n\n");
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
    add_item("bridge","This bridge looks like it is a natural stone "
      "bridge. It crosses over the river.\n");
    add_item(({"water fall","waterfall"}),"You look over the falls but "
      "you can not see the bottom. If you were to jump it would be your "
      "death.\n");

    // Items....

    add_exit("east", ROOM+"ngob22a.c","path");
    // Exits....
} /*setup() */

void init() {
    add_action("jump_fall","jump");
    add_action("listen_rumbling","listen");
    ::init();
}
int listen_rumbling(string str) {
    if(str=="rumbling") {
        write("The water fall is really loud and you think you might be deaf now.\n");
        tell_room(ENV(TP),CNAME + " holds his ears in pain as he "
          "listens to the rumbling of the water fall.\n", (TP));
        return 1;
    }
}
int jump_fall(string str) {
    if(str == "water fall" || str == "off" || "down") {
        write("You die (sigh).\n\n");
        return 1;
    }
}

