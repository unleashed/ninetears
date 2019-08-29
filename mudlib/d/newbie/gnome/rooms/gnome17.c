inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
set_long("Macedonia:  Shadow Valley\n\n"
            "   Footing becomes treacherous as you stumble "
            "over the lose stones and debris that covers the "
            "ground here. The cliff to your south is jutting "
            "at a sharp angle toward the sky. The sound of "
            "rushing water greats your ears from somewhere south. "
            "Unlike the rest of the forest, this area has been "
            "cleared of all trees and bushes that must have been "
            "growing here at some point in time. "
            "\n\n");
add_item(({"stones","debris"}),"Scattered across this entire "
           "field are many rocks and other forms of debris.  "
           "In your opinion, it looks as if this debris was "
           "left from either a construction or mining project "
           "that occurred here in the recent months.\n");
add_item("ground","The ground here is covered by all sorts "
                 
         "of debris.  Unlike the rest of the forest, there "
         "is not even a blade of grass growing within several "
         "feet of the cliff.\n");
add_item(({"cliff","south"}),"With your attention being drawn "
           "by the sound of running water, you notice "
           "something a little strange about this cliff.  "
           "At its base, there is a small hole partially "
           "covered by some of the rubble.\n");
add_item("hole","After moving some of the debris, you notice "
         "that this hole might be big enough for you to enter "
         "in.\n");
add_clone(NPC+"bear.c",1);
add_exit("north",VALLEY +"gnome11","path");
add_exit("northwest",VALLEY +"gnome10","path");
add_exit("northeast",VALLEY +"gnome12","path");
add_property("no_undead", 1);
}
void init()
{
   add_action("do_enter","enter");
   ::init();
}
int do_enter(string str)
{
if(str == "hole")
   {
      write("You crawl into the murky darkness to find ... \n\n");
      this_player()->move("/d/newbie/gnome/tunnels/under04");
      this_player()->look_me();
      return 1;
   }
}
