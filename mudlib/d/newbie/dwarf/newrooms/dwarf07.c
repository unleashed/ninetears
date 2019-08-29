//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Northern Edge of The Pit");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Northern Edge of The Pit\n\n"
	"     This is the northern edge of the huge pit.  You can "
		"hear the sound of rushing water coming from deep within "
		"the pit.  To the south, there is a rickety looking "
		"bridge that crosses over to the other side of the "
		"pit.  There is a ledge to the southeast that leads "
		"around the edge of the pit to a small cave on the "
		"eastern wall.  There is also a crack in the wall that "
		"could be used to climb upwards.  "
		"\n\n");
	add_item("cave","This tiny cave leads into the eastern wall.\n\n");
	add_item(({"pit","bridge"}),"The bridge crosses the huge, deep "
		"pit.  The bridge looks very sturdy despite its "
		"apparent age.  You can hear the sound of an underground "
		"river from deep within the pit.  "
		"\n\n");
	add_item(({"crack","wall"}),"The crack runs upward along the "
		"wall.  You can go up through it to get to the top.  "
		"\n\n");
	add_item("ledge","The ledge here leads around the pit to the "
		"southeast.  It will take you to the small cave in the "
		"eastern wall.\n\n");
add_exit("south",ROOM+"dwarf09","path");
add_exit("southeast",ROOM+"dwarf10","path");
add_exit("up",ROOM+"dwarf04","path");
   add_clone(CHAR+"spider",random(3));
   add_clone(CHAR+"drole",1);
}
