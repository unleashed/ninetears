#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(60);
 set_short("Farmer's Way");
set_long("You are on Farmer's Way.  The way continues to the east and south.  "+
      "To the north is what was once the briefly opened, Happy "+
      "Cow Tavern.  Unfortunately, it recently burned down during an immortal "+
     "act of frustration.  Sadly, the owner did not have any insurance "+
     "and is rumored to be waiting tables in Lady Luck while "+
     "his poor wife begs for coins on the streets of the city.\n\n");
 add_exit("south",ROOM+"farmer1", "road");
 add_exit("east", ROOM+"farmer3", "road");
 add_alias(({"happy cow","happy cow tavern"}), "tavern");
 add_item("tavern",
	"Closed for rebuilding, sorry!\n");
 set_monster(NUM, "city");
 set_zone("city");
}
