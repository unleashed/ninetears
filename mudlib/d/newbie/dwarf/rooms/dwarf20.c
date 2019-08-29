//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Waterfall");
set_light(80);

	set_long("\n   Realm of the Dwarf:  Waterfall\n\n"
	 "     This is the southern end of the sandy beach along "
		"the lake.  The beach ends here at a pile of rocks. "
		"The waterfall begins in a cave near the top of the "
		"southern wall and cascades down onto the rocks and "
		"into the lake.  The thundering sound of the water shakes "
		"the rocks and causes your ears to hurt.  "
		"It looks as if you might be able to climb up the "
		"pile of rocks to the cave at the top where the "
		"waterfall comes out.  "
		"\n\n");
	add_item(({"sandy beach","sand","beach"}),"The sandy shore leads north"
		" along the edge of the lake and goes right up to the "
		"pile of rocks here.  "
		"\n\n");
	add_item(({"pile","rocks","pile of rocks"}),"The rocks look "
		"very loose and slick from the water that has sprayed "
		"on them.  It might be possible to work your way up "    
		"to the top.  "
		"\n\n");
	add_item(({"waterfall","water","lake","spray"}),"The spray "
		"from the waterfall totaly hides your view of the "
		"lake.  You can see the waterfall, though.  It is right "
		"before you.  The sound is so loud that is shakes the "
		"rocks and pounds your ears painfuly.  "
		"\n\n");
add_exit("north",ROOM+"dwarf16","path");
add_exit("up",ROOM+"dwarf23","path");
}
