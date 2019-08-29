//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom2.c";

void setup ()   { my_setup();
	set_short("Realm of the Dwarf:  Entry Room");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Entry Room\n\n"
	 "     You are at the beginning of a cold, dark cave.  "
		"The cave looks as if it once ran north and south, "
		"but there seems to have been a cave-in to the "
		"south.  The cavern to the north is left as the "
		"only apparent exit.  High above you can see a large "
		"shaft that runs upward.  \n\n");
/*
	add_item(({"small sign","sign"}),"The small sign reads:\n\n"
		"+------------------------------------------------+"
		"\n"
		"|                                                |"
		"\n"
		"|      Welcome to the Dwarven newbie area!       |"
		"\n"
		"|                                                |"
		"\n"
		"|       We hope you enjoy your visit here.       |"
		"\n"
		"|                                                |"
		"\n"
		"|        Please feel free to explore this        |"
		"\n"
		"|       area and stay as long as you like.       |"
		"\n"
		"|                                                |"
		"\n"
		"|    There are lots of monsters here to help     |"
		"\n"
		"|              you gain experence.               |"
		"\n"
		"|                                                |"
		"\n"
		"|          Have fun!!       Good luck!!          |"
		"\n"
		"|                                                |"
		"\n"
		"+------------------------------------------------+"
		"\n\n");
*/
	add_item(({"cave-in"}),"The cave is blocked off to the "
		"south by a large cave-in.  There seems to be no "
		"way to get past the fallen rocks.  "
		"\n\n");
	add_item(({"rock"}),"These rocks have fallen to your south, "
		"completely blocking the cave off.  There is no way "
		"get by them.  "
		"\n\n");
	add_item("cave","The cave is cold and damp.  It looks like it "
		"once ran north and south.  "
		"\n\n");
	add_feel(({"wall","rocks"}),"The rocks and the walls are "
		"cold to the touch and damp.  "
		"\n\n");
	add_item("shaft","The shaft above you is out of reach.\n\n");
add_exit("north",ROOM+"dwarf56","path");
}
