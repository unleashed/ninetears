//  Dwarven Newbie Area ---- Created by Mist ---- Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void init()
{
   ::init();
   add_action("col_me","collect");
}

int col_me(string str)
{
   object *stuff;
   int c;
   if(str == "moss")
   {
      stuff = all_inventory(this_player());
      for(c=0; c<sizeof(stuff);c++)
      {
         if((string)stuff[c]->query_name() == "moss")
             {
             write("You have collected some moss already!\n");
             return(1);
             }
          else
             {
             switch(random(5)+1)
             {
      case(1): clone_object(MISC + "blue_moss.c")->move(this_player());
      break;
      case(2): clone_object(MISC + "red_moss.c")->move(this_player());
      break;
      case(3): clone_object(MISC + "green_moss.c")->move(this_player());
      break;
      case(4): clone_object(MISC + "yellow_moss.c")->move(this_player());
      break;
      case(5): clone_object(MISC + "purple_moss.c")->move(this_player());
      break;
      case(6): clone_object(MISC + "orange_moss.c")->move(this_player());
      break;
            }
         write("You scrape a piece of moss from the wall.\n");
            return(1);
         }
      }
   }
   return(0);
}
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Small Room");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Small Room\n\n"
	 "     This is the wall of the cave, overlooking the pit.  "
		"You are in a crack in the wall, about 40 feet from the "
		"floor of the cave.  The crack continues up to a ledge, "
		"and down to the cave floor.  "
		"\n\n");
	add_item(({"wall","crack"}),"This large crack in the wall runs "
		"all the way up to the ledge above.  "
		"The sides of the crack are slippery due to the growth "
		"of some beautiful, multi-colored moss.  "
		"\n\n");
	add_item(({"ledge"}),"The ledge overhead sticks out a bit from "
		"the wall.  But you will have no problem getting to it  "
		"though, the crack gives you easy access to the top.  "
		"\n\n");
	add_item(({"moss","mosses","multi-colored moss"}),"This moss "
		"runs up and down the crack in the wall.  Its colors "
		"fade from blue, purple, and green to yellow, orange, "
		"and red.  You might be able to collect a small sample "
		"of it.  "
		"\n\n");
add_exit("up",ROOM+"dwarf01","path");
add_exit("down",ROOM+"dwarf07","path");
}
