#include "path.h"
inherit "/std/room";
object shovel;

void setup()
   {set_short("Stables");
    set_long("You are in the stables.  You can leave horses here.\n\n");
    set_light(60);
    add_exit("south", ROOM+"hill2", "door");
   }

void reset()
   {if(!shovel)
      {shovel=clone_object("/d/ss/daggerford/items/shovel");
       shovel->move(this_object());
      }
   }

void init() {
   ::init();
   add_action("sec_entrance", "down");
}

sec_entrance() {
   if(((string)this_player()->query_name() == "grozak") ||
      ((string)this_player()->query_name() == "christabel") ||
      ((string)this_player()->query_name() == "grimbrand"))
     {
      this_player()->move("/d/ss/daggerford/stablesII.c");
      this_player()->look_me();
     return 1;
     }
    else
     {
      write("Huh?");
      return 1;
     }
}

void dest_me()
   {if(shovel)
   shovel->dest_me();
 }
