#include "path.h"
 inherit CASTLE+"baseroom2.c";
 void setup() { my_setup();
	set_short("Realm of the Orc:  Mountain Road");
	set_light(40);
   set_long("\n   Realm of the Orc:  Mountain Road.\n\n"
            "     This is the road up and down from the path that leads up "
                 "to the Tower of Grishnath. The mountainwall is covered with "
		 "something red. And it's several scratches there that may "
                 "comes from a sword or something like that.\n\n");



add_property("no_undead",1);
	add_item("tower", "This is the Tower of Grisnath. And you can see a "
		 "red light from one of the windows. Maybe the orcs use that "
                 "to spot their enemies???\n");
	add_item("road", "The road is not in a good shape, but you can still "
		 "walk on it, but you would get problem if you tried to get "
		 "a wagon up here.\n");

	add_item(({"red","wall","mountain"}), "As you look at the wall you "
				"realize that the red is blood "
				"and that it's been there for a "
                           "very long time.  \n");
   add_item(({"scratch","scratches"})," These are marks left by "
       "weapons.  Probably from some battle. \n");
	add_exit("south",CASTLE +"orc36","path"); 
	add_exit("northeast",CASTLE +"orc31","path");
}

