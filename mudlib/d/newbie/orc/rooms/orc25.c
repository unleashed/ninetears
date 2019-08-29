//COBRA
#include "path.h" 


 inherit CASTLE+"baseroom.c";
 void setup() { my_setup();
   add_property("no_undead",1);
	set_short("Realm of the Orc:  Staircase"); 
	set_light(40); 
        set_long("\n   Realm of the Orc:  Staircase.\n\n"
                 "     You are on the path leading up to the Tower of "
		 "Grishnath. The path is solid dirt but you can see some "
		 "footprints on the ground.  Over your head you discover that "
		 "a mountain ledge gives you some protection from the tower.  "
	         "\n\n");

	add_item(({"path", "stairs"}), "This path is leading up to the "
				       "Tower and down from the Tower. "
				       "The path here is covered with "
				       "dirt, but you can see that it is "
				       "roughly made.\n");
	add_item("tower", "You turn your eyes to the tower and you know "
			  "you're looking upon the Tower of Grishnath, " 
			  "home of morbid creatures that haunted your "
			  "childhood.\n");

	add_exit("north",CASTLE +"orc23","path"); 
	add_exit("east",CASTLE +"orc26","path");
	set_zone("staircase");
}//end setup


