#include "path.h"
inherit "/std/newbieguild";
void setup()
  {
  set_short("Realm of the Orc:  Guild Mansion");
set_light(20);
set_long("\n   Realm of the Orc:  Guild Mansion.\n\n"
         "     You stand in what once was a lavish mansion, but now "
"it has been destroyed beyond repair. Many of the walls have been "
"knocked down and boards hang loosely from the top of the second floor "
"where the stairway connected. It is like the mansion has been hollowed "
"out. Orcs of all walks of life come here to try to obtain "
"'position' or 'rank' in their society of brute strength and greed. "
"You notice a group of young orcs all staring mindlessly at a "
"\"sign\".\n\n");
   add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
       "|            %^BOLD%^Orc Adventurer's Guild%^RESET%^                   |\n"
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

add_exit("south", TOWN+"town05.c", "path");
  }

