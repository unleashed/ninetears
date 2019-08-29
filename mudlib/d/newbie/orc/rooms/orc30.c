//COBRA
#include "path.h"  
 inherit CASTLE+"baseroom2.c";
 void setup() { my_setup();
        set_short("Realm of the Orc:  Staircase");  
        set_light(40);  
        set_long("\n   Realm of the Orc:  Staircase.\n\n"
                 "     You are now at the hard part of the path up to the "
		 "the Tower of Grisnath. The path is small and a lot of "
		 "small stones on the ground causes a great danger to "
		 "walk this path. "
		 "\n\n");

        add_item(({"path", "stairs"}), "This path is leading up to the " 
                                       "Tower and down from the Tower. " 
                                       "The stairs here is covered with " 
                                       "dirt and stones that may will give "
				       "you some problems to walk here "
				       ", but you can see that the path " 
                                       "here is roughly made.\n");

	add_item(({"stones","stone"}), "The stone looks ordinary but it "
				       "looks like it has been placed here "
				       "for fun.\n");
 
        add_item("tower", "You turn your eyes to the tower and you know " 
                          "you're looking upon the Tower of Grishnath, "  
                          "home of morbid creatures that haunted your " 
                          "childhood.\n");
        
	add_exit("northwest",CASTLE +"orc29","path"); 
	add_exit("down",CASTLE +"orc32","path");

        set_zone("staircase"); 
}//end setup 

