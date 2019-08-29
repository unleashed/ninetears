// Orc Newbie Area:  Written by Goodfoot 29/03/95.
#include "path.h"
inherit CASTLE+"baseroom2.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Climbing Path");
set_light(40);
   set_long("\n   Realm of the Orc:  Climbing Path.\n\n"
            "     You are on a path slowly leading you upwards.  The "
            "rocks you are "
                "walking among are covered with filth and dirt, and you can spot " 
                "tracks of filty feets covering some of the stones on the path. "
                "You set your feet down among the rocks, carefull not to step on "
                "their sharp edges.\n"
                "On the peak of the mountain, you see a many spired tower "
                ", but the road to it looks long and treacherous.\n\n");
        add_item("tower","You turn your eyes to the fell tower and your " 
                "heart sinks.  You know you're looking upon the Tower of "
                "Grishnath, home of morbid creatures that haunted your " 
                "childhood. There seem to be some sort of an aura radiating "
                "from the topp most pinacle of the tower.\n\n");
        add_item(({"path","road"}), "The road looks well and recently " 
                "used by steel-shod feet.  There are several pock-" 
                "marks where boulders have fallen from above, and parted "
                "rocks lay sparchely spread upward the path.\n\n");
        add_item("rocks","The rocks are all sharp and craggy, like daggers "
                "pointed upwards.  You realize this path was not built " 
                "to keep sore footed travellers away, but to prevent them from "
                "running fast down again.\n\n");
        add_item("filth","The filth on the rocks seems to be a foul mixture " 
                "of dried blood, urine, and feces. You feel like holding your " 
                "breath as you inspect it.\n");
        add_item("pock-marks","They are deep scars in the road's surface.  " 
                "Black, and uninviting, they represent how much care is " 
                "taken to preserve this path.\n");
        add_item("tracks","The tracks has a severe ressemblens to orc feets.\n\n");
add_exit("west",CASTLE +"orc39","path");
add_exit("southwest",CASTLE +"orc42","path");
        set_zone("staircase");
}
