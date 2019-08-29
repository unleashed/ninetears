inherit "/std/room";

#include "path.h"

void init() {
    ::init();
    add_action("do_read","read");
}

void setup() {
    set_light(80);
    set_short("Intersection");
    set_zone("town");
    set_long(
      "This is an intersection, and also the Public Square of the town of "
      "Belgar's Haven. The place seems fairly quiet right now, for the few "
      "people that are here are going about their own business. You can see "
      "that they are dressed in old, shabby clothing, but they don't seem to "
      "mind. There is a large pole in the middle of the square here, with "
      "several messages posted on it.\n");
    add_property("no_undead",1);
    add_clone(NPCS+"elderb.c",1);
    // add_clone(CHAR+"elderb.c",1); put in when errorsare fixed //

   add_exit("post",HERE+"epost","door");
    add_exit("north", HERE+"street1", "path");
    add_exit("west", HERE+"street3", "path");
    add_item("pole", 
      "The pole has several messages posted on it. most are unreadable "
      "because of weather damages and such, but you find a recent one "
      "titled 'NOTICE TO ADVENTURERS' that looks readable.\n");
    add_item(({"note","message","notice"}),
      "This message was posted by the Mayor. It looks like a plea for help..."
      "why dont you read it?\n");
}
int do_read(string str) {
    if(str == "message" || str == "sign")
    {
	write(
	  "==========================================================\n"
	  "|                                                        |\n"
	  "|    Welcome to Final Realms Guest Area.                 |\n"
	  "|                                                        |\n"
	  "|    A few words of introduction:                        |\n"
	  "|    All the areas seen here are actually in             |\n"
	  "|    play somewhere. Just don't expect any logic         |\n"
	  "|    (or fairness) here.                                 |\n"
	  "|    This area is simply to allow you to look around     |\n"
	  "|    and get an idea of what the place is like.         |\n"
	  "|                                                        |\n"
	  "|    There are no rules in this area, other than         |\n"
	  "|    don't shout profanities or otherwise tease          |\n"
	  "|    the animals.                                        |\n"
	  "|                                                        |\n"
	  "|    If you want to start a player, create one and go    |\n"
	  "|    through the newbie areas. These are much tamer      |\n"
	  "|    than this area and give you a chance to get         |\n"
	  "|    aclimatized before facing the big wide world.       |\n"
	  "|                                                        |\n"
	  "|                                                        |\n"
	  "==========================================================\n"
	);
	return 1;
    }
    return 0;
}
