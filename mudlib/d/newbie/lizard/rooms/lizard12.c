#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     As you emerge from the thick parts of the swamp you "
	 "find yourself on a log jutting out into the deeper "
	 "waters of the swamp. The water looks extremely deep here. "
	 "You can see small grotesque looking fish swimming just "
	 "below the surface. Maybe this is the place that the "
	 "Old man was speaking of. \n\n");
add_property("no_undead",1);
add_item("water", " The water here is extremely deep. You can see "
	 "things swimming around in here, maybe you would like "
	 "to try  it too? \n\n");
add_exit("east",SWAMP +"lizard13","room");
}
void init()
{
  add_action("do_swim", "swim");
  ::init();
}
int do_swim()
{
if(this_player()->query_properties("skill_swimming"))
     {
this_player()->move("/d/newbie/lizard/underwater/uw01.c");
         this_player()->look_me();
      return 1;
     }
   else
     {
        write("As you jump into the water, you suddenly realize "
               "that you cannot swim.  As you thrash around and gasp for "
             "air, you fortunately grab ahold of the log and pull "
             "yourself up.  \n");
        return 1;
     }
}
