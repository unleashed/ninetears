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
set_short("Realm of the Dwarf:  Dead End");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Dead End\n\n"
	 "     The path between the rocks has led you nowhere.  "
		"There is nothing here but the cave wall and the "
		"sand.  Over in one corner, there is a hole in the "
		"sand here that looks like a small animal has dug "
		"out a nest.  There are a number of small holes in the "
		"walls here.  The only way out of here is the path "
		"to the east.  "
		"\n\n");
	add_item(({"wall","cave wall","rocks"}),"The rock wall "
		"surrounds you on three sides.  The rocks are rough "
		"and extend upward way above your head.  "
		"There are several holes in the "
		"walls here.  One that is a bit larger than the others "
		"is full of some multi-colored moss.  "
		"\n\n");
	add_item(({"hole","sand","corner","nest"}),"There is a small "
		"nest burrowed in the sand in one corner.  It looks "
		"as if a small animal lives in this area.  "
		"\n\n");
	add_item(({"moss","mosses","multi-colored moss"}),"This moss "
		"is stringy and very colorful.  The colors fade from "
		"blue, purple, and green to yellow, orange, and red.  "
		"You might be able to collect a small amount of it.  "
		"\n\n");
add_exit("east", ROOM+"dwarf06.c", "path");
add_clone(CHAR +"spider.c", 1);
}


