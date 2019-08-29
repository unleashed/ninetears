//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997
int i;
int d;

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Flooded Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Flooded Cave\n\n"
            "   As you step forward, your feet slide down the slick "
            "underwater rocks and you finally reach bottom, just as the "
            "cold water slaps at your neck.  Movement here is difficult "
            "due to the depth of the water and the strength of the "
            "current.  The water seems to get a bit shallower to the "
            "northwest and the south.  There is a small tunnel off "
            "to the southwest that is far above you, however it may be "
            "possible to climb up there.  "
		"\n\n");
add_exit("south",ROOM+"dwarf63","path");
add_exit("northwest",ROOM+"dwarf50","path");
add_exit("southwest",ROOM+"dwarf62","path");
}
void init(){
::init();
   add_action("go_sw","southwest");
   add_action("go_sw","sw");
   }

go_sw()
{
   d=this_player()->query_dex();
   i=(random(20));
   if(i>(d))
      {
   write("You attempt to pull your way out of the water, but your "
         "hands fail to grip the slimy rocks and you fall "
         "back into the cold water with a loud splash.\n\n");
      return(1);
      }
      else
      {
   write("You find a solid grip and pull yourself up out of the water.\n\n");
      return(0);
      }
}
