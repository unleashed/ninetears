//  Dwarven Newbie Area:  Created By Mist   Fall 1994

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
set_short("Realm of the Dwarf:  Hole in the Wall");
set_zone("CAVE");
set_light(15);
	set_long("\n   Realm of the Dwarf:  Hole in the Wall\n\n"
	 "     You crawl your way into the hole in the wall.  "
		"It is a tight squeeze but you have made it in.  "
		"There are a number of small holes here on the cave "
		"wall.  They have something squishy in them. "
		"You can see the main part of the cave to the "
		"southwest and to the northeast there is a large, "
		"well lighted room with the smell of guano coming "
		"from it.  "
		"\n\n");
	add_smell(({"guano","path"}),"The smell coming from the room " 
		"to the northeast is the most horrible thing you "
		"have ever smelled of in your life.  You recognize "
		"it to be guano, the disgusting waste of bats.  "
		"Considering the incredible power of the smell, "
		"there must be lots of bats in that room.  "
		"\n\n");
	add_item(({"wall","hole","something"}),"The holes here in the "
		"walls are packed with some strange variety of moss.  "
		"\n\n");
	add_item(({"moss","mosses"}),"This variety of multi-colored "
		"moss has colors that fade from blue, purple, and green "
		"to yellow, orange, and red.  It might be possible "
		"for you to collect a small piece of it.  "
		"\n\n");
 add_clone(CHAR+"goblin.c",1);
add_exit("southwest",ROOM+"dwarf24","path");
add_exit("northeast",ROOM+"dwarf19","path");
}
