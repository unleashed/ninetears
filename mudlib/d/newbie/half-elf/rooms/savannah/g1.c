//Ljen nov -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_short("Savannah: Oase");
   set_long("You have entered an oase in this savannah, where the animals"
	    " come to drink and hang out. There are many large trees here"
	    " providing shadow from the burning sun. This seems like a good"
	    " place to rest your bones before you explore further.\n");

    set_light(80);

    add_clone(NPC+"lion.c", 1);
    add_clone(NPC+"hyena.c", 1);
    add_clone(NPC+"tiger.c", 1);

    add_exit("west",   SAVANNAH+"f1"  ,   "path");

}
