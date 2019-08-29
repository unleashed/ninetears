//COBRA
#include "path.h"
 inherit CASTLE+"baseroom.c";
 void setup() { my_setup();
   add_property("no_undead",1);
	set_short("Realm of the Orc:  Staircase"); 
	set_light(40); 
        set_long("\n   Realm of the Orc:  Staircase.\n\n"
                 "     You are at the last part of the path up to the "
		 "top of the cliff.  There are some orcs here that's  "
		 "patrolling up and down the path around the mountain.  "
            "Looking up the path you can see the tower looming over "
            "you and a look down causes a light dizzy feeling.  "
		 "\n\n");

	add_item(({"path", "stairs"}), "This path is leading up towards the "
	                               "tower and down to the village below.  "
				       "The stairs here are covered with "
				       "dirt, but you can see that they are "
				       "roughly made.\n\n");
	add_item("tower", "You turn your eyes to the tower and you know "
			  "you're looking upon the Tower of Grishnath, " 
			  "home of morbid creatures that haunted your "
			  "childhood.\n\n");
/* taken out by Tek, was interfering with the attacking of orcs
	add_item(({"orcs", "orc"}), "The orcs looks pretty ugly like a orc "
        "shall do. They are pretty busy patrolling "
        "up and down the path so it's best not to "
        "bother them.\n\n");
*/
	add_exit("south",CASTLE +"orc25","path"); 
	add_exit("up",CASTLE +"orc21","path");
	set_zone("staircase");
}//end setup


