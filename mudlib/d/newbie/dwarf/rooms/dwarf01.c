
//  Dwarven Newbie Area ---- Created by Mist ---- Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Pit Overlook");
set_light(40);
set_long("\n   Realm of the Dwarf:  Pit Overlook\n\n"
	"     This is a ledge that overlooks the great pit.  You "
		"can barely make out the sound of rushing water down "
		"below.  There is a crack in the wall that looks at if "
		"it could be used to go down to the cave floor.  To the "
		"east there is some source of bright light.  This might "
		"be an exit from the cave.  "
		"\n\n");
	add_item(({"crack"}),"Thi crack is big enough for you do use "
		"to climb down to the floor below.  "
		"\n\n");
	add_item(({"ledge","overlook","pit"}),"This ledge overlooks "
		"the huge pit that covers most of the floor below.  "
		"\n\n");
add_exit("east",ROOM+"dwarf02","path");
add_exit("down",ROOM+"dwarf04","path");
}
