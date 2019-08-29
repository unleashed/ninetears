// Modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun - Main Entrance");
   set_long("You are standing in front of the entrance to a big castle. The "
            "gate is made of iron and it has been designed to support the "
            "assaults of the enemies.  The walls are made of solid rocks "
            ",specially made to fit in with each other, modelated "
            "by the wise hands of the wizards of the past. The small "
            "embrasures are the only openings in this walls, which still "
            "stands after numerous years.\n");

   add_item("gate", " A huge iron gate, currently open to welcome you inside.\n");

   set_light(50);

   add_clone(NPC+"high_c",1);

   add_exit("east",   SAVANNAH+"a4.c",   "path");
   add_exit("west",   CAST+"e4.c",     "door");
}

    
