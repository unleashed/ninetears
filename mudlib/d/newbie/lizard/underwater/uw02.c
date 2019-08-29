#include "path.h"
inherit "/std/room";
void setup(){
set_light(50);
set_short("Realm of the Lizard:  Underwater");
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     As you continue your journey down here, you think how much"
         " being able to swim does for you.  More ways to get food,"
         " easy way to escape hunters, and just a good way to relax. "
         " Off to the south you spot a school of fish swimming through"
         " a group of plant life.  It is awful dark to the southwest, "
         " it maybe dangerous.  Being adventurous as you are, you will"
         " probably check it out.\n");
add_item("fish", "This is a small school of fish.  They are a lot more"
         " graceful underwater than clumsy you is.\n");
add_exit("east", UWATER+"uw01.c", "path");
add_exit("northwest", UWATER+"uw03.c", "path");
add_exit("west", UWATER+"uw04.c", "path");
add_exit("southwest", UWATER+"uw05.c", "path");
}
