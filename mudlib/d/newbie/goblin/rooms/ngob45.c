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
	 "     The water here is almost black, probably from lack of "
  "circulation. There is a scum floating on the surface which "
  "makes it hard to see the bottom of the river. The river "
"continues to the northeast and to the south.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
"with moss and fungus.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("scum","This is some really interesting scum. Your "
  "stomach growls with hunger.\n");
add_item("river","This river doesn't look to deep as far as you "
"can tell, maybe about two feet deep. You see some blind fish swimming "
"in it occassionally.\n");
add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
"they look quite tasty.\n");

// Items....

add_exit("northeast", ROOM+"ngob46.c","path");
add_exit("south", ROOM+"ngob43.c","path");
// Exits....

add_clone(CHAR+"drole.c",1);
} /*setup() */

void init() {
add_action("eat_scum","eat");
::init();
}
int eat_scum(string str) {
if(str=="scum") {
write("Ummmmmm. That was tasty.\n");
tell_room(ENV(TP),CNAME + " eats some scum off the surface "
"of the water.\n", (TP));
return 1;
}
}
