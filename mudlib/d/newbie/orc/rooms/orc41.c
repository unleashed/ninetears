// Orc Newbie Area:  Created by Benedick sometime in 1995.
#include "path.h"
inherit CASTLE+"baseroom.c";
 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Craggy Path");
set_light(40);
   set_long("\n   Realm of the Orc:  Craggy Path.\n\n"
            "     You are on a winding craggy path leading up a mountain "
		"face.  The rocks are black and covered with filth, and " 
		"there are pieces of refuse littering the area.  At the " 
		"peak of the mountain, you see a many spired tower, but " 
		"the road to it looks long and treacherous.\n");
	add_item("tower","You turn your eyes to the fell tower and your " 
		"heart sinks.  You know you're looking upon the Tower of "
		"Grishnath, home of morbid creatures that haunted your " 
		"childhood.\n");
	add_item(({"path","road"}), "The road looks well and recently " 
		"trodden upon by steel-shod feet.  There are several pock-" 
		"marks where boulders have fallen from above.\n");
	add_item("rocks","The rocks are all sharp and craggy, like daggers "
		"pointed upwards.  You realize this place was not designed " 
		"to keep travellers away, but to prevent them to escape.\n");
	add_item("filth","The filth on the rocks seems to be a foul mixture " 
		"of dried blood, urine, and feces.  You reel and heave as " 
		"you inspect it.\n");
	add_item("refuse","The refuse seems to be small pieces of bone "
		"that have been cast aside, broken arrowheads and shafts, " 
		"and heaps of animal excretia.\n");
	add_item("pock-marks","They are deep scars in the road's surface.  " 
		"Black, and uninviting, they represent how much care is " 
		"taken to preserve this path.\n");
	add_item("boulders","There are no boulders, only small pieces of " 
		"rock that were wrented off in the fall.\n");
add_exit("southwest",TOWN +"town06","path");
add_exit("east",CASTLE +"orc42","path");
}


