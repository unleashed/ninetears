//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h";
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  The Pit");
set_zone("CAVE");
set_light(40);
	set_long("\n   Relam of the Dwarf:  The Pit\n\n"
	 "     You have come to the edge of a very deep and dark "
		"pit in the center of the cave floor.  The pit covers "
		"almost all of the floor and would be a serious problem "
		"for you if it were not for the bridge that crosses "
		"over to the other side.  From deep within the pit "
		"comes the sound of very fast moving water.  There must "
		"be an underground river down there.  There seems to be a "
		"ledge going northeast that leads to another tunnel "
		"in this vast cave network.  There is the sound of "
		"rushing water coming from the tunnel to the south.  "
		"\n\n");
	add_item(({"pit"}),"The pit is very dark and deep and takes "
		"up most of the room.  There is a small ledge that leads "
		"around to the east.  From deep within the pit comes the "
		"sound of rushing water.  "
		"\n\n");
	add_item(({"bridge"}),"This bridge is made of ropes and wooden "
		"planks and is attached to poles that have been driven "
		"into the floor here.  "
		"\n\n");
	add_item(({"ledge"}),"The ledge goes around the pit to the "
		"east and can be used to get to the small tunnel in the  "
		"east wall.  "
		"\n\n");
	add_item(({"rope","plank"}),"The ropes are tied around the "
		"planks in such a manner as to make a bridge that "
		"looks sturdy despite its age.  The ropes are attached "
		"to poles at each end.  "
		"\n\n");
	add_item(({"pole"}),"The poles that hold the bridge up are "
		"driven into the floor here.  It must have been a major "
		"job because the floor here is solid rock.  "
		"\n\n");
	add_item(({"floor"}),"The cave floor here is solid rock.  "
		"\n\n");
add_exit("south",ROOM+"dwarf18","path");
add_exit("north",ROOM+"dwarf09","path");
add_exit("northeast",ROOM+"dwarf10","path");
add_clone(CHAR+"goblin.c",2);
add_clone(CHAR+"cave_rat.c",1);
}
