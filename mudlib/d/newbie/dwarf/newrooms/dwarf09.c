//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  On The Bridge");
set_light(40);
	set_long("\n   Realm of the Dwarf:  On The Bridge\n\n"
	 "     This is the center of the bridge that crosses the "
		"huge pit.  It is quite a bit more sturdy than is looks.  "
		"The floor boards are strong and the rope seems to be in "
		"excellent shape.  The sound of rushing water greets "
		"your ears from deep within the pit.  It sounds as if "
		"there is an underground river down there.  To the north "
		"the bridge ends next to the cave wall.  To the south "
		"is the other edge of the pit.  Looking east, you can "
		"see a small tunnel in the wall.  There is light coming "
		"from inside of it somewhere.  "
		"\n\n");
	add_item(({"bridge","boards","rope"}),"The bridge is in suprisingly "
		"good shape considering its obvious age.  The boards are "
		"strong and solid and the ropes are tight and in good "
		"shape.  "
		"\n\n");
	add_item(({"pit"}),"The pit is dark and deep.  So deep in fact "
		"you are unable to see the bottom.  You are able to hear the "
		"sound of rushing water at the bottom of the pit.  "
		"There must be a river at the bottom of the pit.  "
		"\n\n");
	add_item(({"tunnel","wall"}),"The tunnel goes into the eastern "
		"wall.  There is a faint light coming from within the "
		"tunnel.  "
		"\n\n");
add_exit("south",ROOM+"dwarf14","path");
add_exit("north",ROOM+"dwarf07","path");
}
