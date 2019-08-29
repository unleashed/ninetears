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
	 "     The tunnel ends here in this open cavern. Its not a very "
  "large cavern, being only about twenty feet by twenty-five feet. "
  "There is garbage and kegs laying around all over the place. "
  "It looks like someone had a party here. The only exit is to "
"the southwest back the way you came.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item(({"ground","floor"}),"The ground is covered in garbage and beer kegs. "
  "\n\n");
add_item(({"keg","kegs","beer kegs"}),"These kegs are empty, not "
 "even a drop of beer left, unfortunatly.\n");
add_item("garbage","This is mostly useless stuff covered in puke and "
"excretment. You see something shiny in the garbage.\n");

// Items....

add_exit("southwest", ROOM"ngob27.c","path");
// Exits....
} /*setup() */

void init() {
add_action("do_search","search");
::init();
}
int do_search(string str) {
  if(!str)
 {
 write("\nYou search around but don't find anything interesting\n");
 return 1;
 }
 else
if(str=="garbage") {
   if(this_player()->query_property("GOBLIN_SWORD"))
   {
      write("You search the garbage completely and find nothing.\n");
      return 1;
   }
   else
   {
write("You have found a sword, it appears to have some "
  "writing on it.\n");
new(WEAPON+"ques_sword.c")->move(this_object());
this_player()->add_property("GOBLIN_SWORD",1);
return 1;
}
}
}

