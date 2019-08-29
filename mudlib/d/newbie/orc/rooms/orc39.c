// Orc Newbie Area:  Written by Goodfoot 29/03/95.

#include "path.h"
 inherit CASTLE+"baseroom2.c";
 void setup() { my_setup();
set_short("Realm of the Orc:  Steep Path");
set_light(40);
   set_long("\n   Realm of the Orc:  Steep Path.\n\n"
            "     The path goes alongside the wall here for a while.  "
                "and then it turns upwards, in a steep climbing. You "
                "see the path in front of you is covered by filth and dirt, and " 
                "you can see claw-marks on some of the stone in the steep "
                "climbing.\n"
                "On the peak of the mountain, you see a many spired tower, "
                " but the road further on looks long and treacherous.\n\n");
add_item("tower", " \n"
"  The tower has many spires all grasping toward the heavens. "
"The spires are long and look fiendish as if some evil cult designed it.\n\n");
        add_item(({"path","road"}), "The road looks recently " 
                "used by steel-shod feet.  There are several pock-" 
                "marks where boulders have fallen from above, and parted, "
                "sharp rocks lay sparchely spread upward the path.\n\n");
        add_item("rocks","The rocks are all sharp and craggy, like daggers "
                "pointed upwards.  You realize this path was not built " 
                "to keep sore footed travellers away, but to prevent them from "
                "running fast down again.\n\n");
        add_item(({"filth","dirt"}),"The filth on the rocks seems to be a foul mixture " 
                "of dried blood, urine, and feces. The place stinks, and you feel like " 
                "holding your nose as you look at it.\n\n");
        add_item("pock-marks","They are deep scars in the road's surface.  " 
                "Black, and uninviting, they represent how much care is " 
                "taken to preserve this path.\n\n");
        add_item(({"marks","claw_marks"}),"They seem to originate from small "
                "claws. And the carves aren't specially deep in the rocks.\n\n");
        set_zone("staircase");
add_exit("east",CASTLE +"orc40","path");
add_exit("up",CASTLE +"orc38","path");
}

