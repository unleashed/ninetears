#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Stairs");
set_light(40);
set_long("\n   Realm of the Orc:  Stairs.\n\n"
         "     You are standing in a narrow, twisting staircase "
         "leading to the "
	"top of the tall tower you saw outside.  There are torch-holders along "
	"the walls, but you think no light has sat in them for many long years "
	"uncounted.  There is a reek of death in the air.\n\n");
	add_item(({"torch holders","holders"}),"The torch holders are bent with age and abuse, and anything that was once "
	"beautiful about them has been raped by the marauding orcs.\n");
	add_item(({"walls","wrents"}),"The once smooth walls have been molested with great wrents from various large "
	"weapons being thrust into them.  A battle was fought here, on these "
"dreaded stairs, and you are filled with glee with the knowledge that "
"it was your fellow orcs that won the day.\n");
	add_smell("reek","It is the smell of dried blood, overpowered by excretia, and the remains of "
	"the decayed viscera not eaten by the captors of this castle.\n");
add_exit("up",TOWER +"tower02","room");
add_exit("down",CASTLE +"orc01","room");
}
