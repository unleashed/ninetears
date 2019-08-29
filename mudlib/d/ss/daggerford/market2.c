#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 1

object merchant;

void setup()
{
	set_light(80);
	set_short("Market square");
	set_long(
"You are in the middle of the market square. People are everywhere "+
"around you. There's a giant structure to the west and a shop to the east. "+
"The market continues north and south.\n");

	add_exit("south", ROOM+"market1", "road");
	add_exit("east", ROOM+"korbus","door");
	add_exit("north", ROOM+"market3", "road");
    add_exit("west", "/d/ss/daggerford/fist/entrance","road");

	add_item("people",
		"They're milling around, pushing into you and making noise.\n");
	add_item("shop", "You can't see much of it due to the crowd.\n");
	add_item("structure", "You can't see much of it due to the crowd.\n");
	add_alias("square", "market");
	add_alias("market square", "market");
	add_item("market", "Lots of people and merchants are milling around.\n");

	set_zone("city");
	set_monster(NUM, "city");
}

void reset()
{
	::reset();
	if(!find_living("edmund"))
	{
	 merchant=clone_object(CHAR+"edmund");
         merchant->move(this_object());
	}
}
