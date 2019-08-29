#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You've been walking for some time now. You have a "
	 "strange feeling that you've seen this place before, maybe it's "
	 "just because one part of the swamp looks just like the "
	 "rest of the swamp to you. It's kind of dark here, which doesn't "
	 "really suprise you. As  you look around you start to "
	 "see a few more trees not many though. There is some more "
	 "of those hungry looking vines around here. \n\n");
add_property("no_undead",1);
add_item("path", "The path is starting to become a little more "
	 "visable. \n");
add_item("vine", "This is another one of those hungry looking vines"
	 ",although this one looks a little larger than the "
	 "others you have seen so far. \n");
add_exit("west",SWAMP +"lizard03","room");
add_exit("southeast",SWAMP +"lizard08","room");
add_clone("/d/newbie/lizard/npcs/gator.c", 1);
}
