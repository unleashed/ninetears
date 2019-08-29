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
set_short("Realm of the Dwarf:  Long Tunnel");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Long Tunnel\n\n"
	 "     The sound of the rushing water is almost deafening "
		"here.  You must be getting very close to the source.  "
		"The dirty cave walls seem to close in on you giving "
		"you an eerie feeling.  Something touches your "
		"shoulder. Do you dare look?  "
		"There is a little more light here and you can see that "
		"it is much brighter to the north.  To the south, the "
		"cave has a bend in it.  "
		"\n\n");
	add_item(({"wall","something","cave"}),"The low cave wall is "
		"covered with moss and crud.  This must have been what "
		"was on your shoulder.  "
		"\n\n");
	add_item(({"moss","mosses"}),"This multi-colored moss hangs "
		"from the cave walls.  Its colors fade from blue, purple, "
		"and green to yellow, orange, and red.  You could "
		"probably collect a small sample of this moss to take "
		"with you. \n\n");
	add_item("crud","This cave wall is covered with this filthy "
		"crud everywhere except where the moss is growing.  "
		"\n\n");
add_exit("south",ROOM+"dwarf27","path");
add_exit("north",ROOM+"dwarf18","path");
add_clone(CHAR+"cave_rat2.c",2);
}
