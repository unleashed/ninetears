#include "path.h"
inherit "/std/newbieguild";
void setup()
  {
set_short("Realm of the Goblin:  Newbies Guild Room");
set_light(20);
set_long("\nRealm of the Goblin:  Newbies Guild Room\n\n"
	 "     This is a small, and dimly-lit cave just off to the "
            "side of the main cave.  The walls are covered with "
            "drawings and carvings that have been left here by "
            "the Goblin adventurers that have gotten their start "
            "here.  There is a small sign here that might tell you "
   "what to do here. You see a temple to the east. "
            "\n\n");
   add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
       "|            %^BOLD%^Goblin Adventurer's Guild%^RESET%^                |\n"
       "|                                                     |\n"
       "|      'cost' To find the XP cost to advance.         |\n"
       "|      'advance' To advance your skills.              |\n"
       "|      'info' To get some information.                |\n"
       "|                                                     |\n"
       "|      You cannot advance above level 5 here.         |\n"
       "|                                                     |\n"
       "+-----------------------------------------------------+\n"
       "\n");
   add_item(({"carvings","drawings"}),"  The drawings and carvings "
       "are very old.  You are unable to make them out. \n\n");

add_exit("east",ROOM+"raiserm.c","door");
add_exit("south", ROOM+"entrance.c", "path");
  }

