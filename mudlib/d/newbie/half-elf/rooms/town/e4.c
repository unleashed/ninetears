//Ljen nov -96
//Coded by Yalaba on the 11th of September of '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_light(80);
   set_short("Jungle Town - Shaman Shack");
   set_long("The biggest and most comfortable shack in the town is indeed a "
           "paradise for those who love the magic and the nature.  All the "
           "furniture has been made using the trunk of the tree itself. "
	   "They can't be moved, but that is no problem, since they are "
           "placed perfectly in order to each other. "
           "The tree is not dead, it is constantly growing and expanding"
           " in the room. But the magic you can sense in here are restraining "
           "the tree from destroying the room. "           
           "The sofa you can see to the north is surrounded by leafs making it "
           "very comfortable: warm in the winter and cold in the summer. " 
	   "There are four windows here, one on each wall.\n");

   add_clone(NPC+"shaman.c",1);

   add_exit("west", TOWN+"d4",  "door");
}

