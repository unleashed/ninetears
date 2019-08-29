//COBRA
#include "path.h"  
  inherit CASTLE+"baseroom2.c";
 void setup() { my_setup();
   add_property("no_undead",1);
        set_short("Realm of the Orc:  Staircase");  
        set_light(45);  
   set_long("\n   Realm of the Orc:  Staircase.\n\n"
            "     You are now past the hard section of your trek up "
            "this mountain.  Looking down you can see the town and "
           "people moving about.  A glance upward reveals the "
           "tower looming over you.  "
		 "\n\n");
add_item(({"town","people"}), "\n"
"  The town's inhabitants look like tiny bugs waiting to be squished. "
"Unfortunately, you are not that big.\n");

add_item("tower", "\n"
"  The tower has several spires all reaching for the heavens. "
"It looks fiendish in many ways.\n\n");
        add_item(({"path", "stairs"}), "This path is leading up to the " 
                                       "Tower and down from the Tower. " 
                                       "The stairs here is covered with " 
                                       "dirt, but you can see that it is " 
                                       "roughly made.\n"); 
	add_exit("southeast",CASTLE +"orc30","path"); 
	add_exit("up",CASTLE +"orc28","path"); 

        set_zone("staircase"); 
}//end setup 


