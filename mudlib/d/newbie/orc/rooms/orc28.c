
#include "path.h"   
 inherit CASTLE+"baseroom2.c";
 void setup() { my_setup();

        set_short("Realm of the Orc:  Staircase");   
        set_light(40);   
   set_long("\n   Realm of the Orc:  Staircase.\n\n"
            "     You are standing on a path that leads up the mountain "
            "to the Tower of Grisnath.  You survey your surroundings "
            "to find that you are quite a ways up the mountain.  In "
            "fact, you are much higher than expected.  The path "
            "continues to the northwest and also goes down here.  "
                 "\n\n"); 

        add_item(({"path", "stairs"}), "This path is leading up to the "  
                                       "tower and down towards the village. "  
                                       "The stairs here are covered with "  
                                       "dirt, but you can see that it is "  
                                       "roughly made.\n");  
        add_item("tower", "You turn your eyes to the tower and you know "  
                          "you're looking upon the Tower of Grishnath, "   
                          "home of morbid creatures that haunted your "  
                          "childhood.\n"); 
         
        add_exit("northwest",CASTLE +"orc26","path");  
        add_exit("down",CASTLE +"orc29","path"); 

        set_zone("staircase");  
}//end setup  


