#include "path.h"
inherit "/std/newbieguild";
void setup()
  {
set_light(20);
set_short("Realm of the Dwarf:  Advancing guild");

set_long("\n   Realm of the Dwarf:  Advancing guild\n\n"
	 "     This is a small dimly-lit room just off to the "
            "side of the main cave.  The walls are covered with "
            "drawings and carvings that have been left here by "
            "the Dwarven adventurers that have gotten their start "
            "here.  There is a small sign here that might tell you "
            "what to do here.  "
            "\n\n");
add_property("no_undead",1);
   add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
       "|           %^BOLD%^Dwarven Adventurer's Guild%^RESET%^                |\n"
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

add_exit("east",ROOM+"dwarf40.c","door");
  }

