#include "path.h"
inherit "/std/newbieguild";
void setup()
  {
set_short("Realm of the Lizard:  Newbie's Guild");
set_light(70);
set_long("\nRealm of the Lizard:  Newbie's Guild\n\n"
    "This is where young lizard-man adventurers come to train. "
  "The walls are covered with "
            "drawings and carvings that have been left here by "
            "the Lizard-men adventurers that have gotten their start "
            "here.  There is a small sign here that might tell you "
   "what to do here."
            "\n\n");
   add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
       "|          %^BOLD%^Lizard-Man Adventurer's Guild%^RESET%^                |\n"
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

add_exit("north",ROOM+"lizard26.c","door");
add_clone("/d/newbie/lizard/npcs/gilreath.c", 1);
  }

