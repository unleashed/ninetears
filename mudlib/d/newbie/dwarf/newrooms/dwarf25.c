//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
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
set_short("Realm of the Dwarf:  Behind Waterfall");
set_zone("CAVE");
set_light(40);

   set_long("\n               Realm of the Dwarf:  Behind Waterfall\n\n"
            "   The water crashes onto the rocks in front of you "
            "with a thunderous sound.  The spray coming from the falls "
            "is soaking you with icy cold water.  You are "
            "standing on a small pathway that leads behind the fall "
            "to what looks like a small opening to the south.  "
		"\n\n");

   add_item(({"water","waterfall","spray","falls"}),"The waterfall is "
              "loudly spilling water into the lake and soaking you with "
              "its cold spray.  Any movement towards the falls could "
              "be disasterous, as the force of the falling water would "
              "be sure to pull you in.  "
              "\n\n");
   add_item(({"rocks"}),"The rocks are worn smooth by the force of "
              "the water hitting them.  Patches of moss grow on many "
              "of them making walking treacherous. "
              "\n\n");
   add_item(({"moss"}),"This moss covers many of the rocks here.  The "
              "colorsfade from blue, purple, and green to red, "
              "yellow, and orange.  It might be possible for you to "
              "collect a small sample of it. "
              "\n\n");
   add_item(({"opening","cave"}),"\n   You can see a small opening "
              "in the southern wall, directly behind the waterfall.  "
              "With the amount of water that is flowing into it, this "
              "cave must run very deep.\n\n");
add_exit("west",ROOM+"dwarf24","path");
add_exit("northeast",ROOM+"dwarf21","path");
}
