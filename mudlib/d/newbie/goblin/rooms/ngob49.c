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
	 "     You stand on a small poorly made bridge that crosses over "
"a large hole in the tunnel floor. It is said that many goblins have been"
" swallowed by the maw for peering at it. It is said"
" that a balrog once had a great battle here with a great wizard."
" It would be wise to leave here at once, you can feel the danger.\n\n");

add_property("no_undead",1);
add_item(({"hole"}),
"This large hole can only be crossed by using the bridge. The hole is called the maw a place of evil. Goblins often tell thier children that if they are bad they will be thrown into the maw.\n");
add_item(({"bridge"}),
"This rope bridge is thick with dust.\n");
add_item(({"rope"}),
"The rope looks like it has been on fire.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("dust","This dust has been here awhile.\n");
add_item(({"foot prints","prints"}),"You see some foot prints but "
"they have been smeared in too much to tell where they go.\n");

// Items....

add_exit("west",ROOM+"ngob32.c","path");
add_exit("northeast",ROOM+"ngob33.c","path");
// Exits....

add_clone(CHAR+"drole.c",2);
} /*setup() */

void init() {
add_action("peer_maw","peer");
::init();
}
int peer_maw(string str) {
if(str=="maw") {
write("You peer into the depths of the maw. You see something moving"
" and glowing suddenly you are hit in the face with two fireballs"
" instantly your eyes are burned to cinders.\n");
tell_room(ENV(TP),CNAME + " peers into the depths of the maw. "
"suddenly two fireballs strike them in the face. The heat from the fire"
" almost knocks you off the bridge and into the depths of the maw.\n", (TP));
return 1;
}
}
