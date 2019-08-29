//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h";
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
add_clone(CHAR+"caverat.c",1);
   }
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Ledge");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Ledge\n\n"
	 "     This is a narrow ledge that goes around the pit.  "
		"The footing here is not too good, so it might be a "
		"good idea to be very careful.  The sound of water "
		"can be heard from deep within the pit.  The ledge continues "
"northwest and southwest, and there is a small tunnel "
		"here that leads east.  There is light coming from "
		"somewhere in there.  "
		"\n\n");
	add_item(({"ledge"}),"The ledge here is very narrow.  It would "
		"be wise to watch your step.  The ledge leads around "
		"the pit.  "
		"\n\n");
	add_item(({"pit"}),"The pit is very deep, you cannot see the "
		"bottom, but you can hear the sound of rushing water "
		"from down there.  Must be a river at the bottom.  "
		"There are big clumps of something lining the edge of "
		"the pit.  "
		"\n\n");
	add_item(({"tunnel","passage"}),"The tunnel leads into the "
		"eastern wall.  It looks as if there is light coming "
		"from within the tunnel.  "
		"\n\n");
	add_item(({"clumps"}),"These are large clumps of some kind of "
		"multi-colored moss.  The moss clings to the inside "
		"of the pit wall.  "
		"\n\n");
	add_item(({"moss","mosses","multi-colored moss"}),"This moss "
		"is very beautiful and the colors fade from blue, "
		"purple, and green to yellow, orange, and red.  "
		"If you are careful you might be able to collect "
		"a specimen of it.  "
		"\n\n");

add_exit("east",ROOM+"dwarf11","path");
add_exit("southwest",ROOM+"dwarf14","path");
add_exit("northwest",ROOM+"dwarf07","path");
}
