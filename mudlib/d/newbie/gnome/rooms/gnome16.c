inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
set_long("Macedonia:  Shadow Valley\n\n"
	"     This is rumoured to be the most beautiful resting "
            "spot in all of Shadow Valley.  From this small hill "
            "at the southwestern corner of the Whispering Woods "
            "You can see many different atmospheres.  A river "
            "leads north, a forest grows to the east, a large "
            "mountain range rests to the north, and there is a "
            "cliff to the south.  But the most beautiful sight "
            "in this area is the waterfall to the south forming "
            "The Gnude River.  "
            "\n\n");
add_item("waterfall","Coming from the top of the cliff, "
         "is a huge waterfall.  As the water falls to the "
         "ground, its course is somewhat changed by coming "
         "in contact withe the cliff.  When it reaches the "
         "river, there is a fine mist of water sprayed "
         "over the area.\n");
add_item(({"river","gnude river","gnude"}),"This is the gentle "
          "flowing Gnude River.  Although it is so gentle, it is "
          "too deep to wade in and to wide to swim across\n");
add_item(({"mountain","range","mountain range"}),"Far too the "     
           "distance you can see the Mithril Mountains.  The "
           "base of the mountains in pretty clear but the peaks "
           "are somewhat covered by the clouds.\n");
add_item(({"forest","woods"}),"From here, you can see the edge of "
           "the forest.  Due to its density, you can not see far "
           "into it.\n");
add_item("cliff","This is a very steep cliff which looks next to "
         "impossible for a young adventurer like yourself to "
         "climb.  Also, about half way up this cliff, there is "
         "a small ledge.  You think to yourelf that if you could "
         "get up there, the scenery must be beautiful.\n");
add_item("ledge","This is a small ledge about half way up the "
         "cliff.  From here you can not tell what is up there, but "
         "looking closely, you can see something.  You just are not "
         "sure what that something is.\n");
add_exit("north",VALLEY +"gnome09","path");
add_exit("northeast",VALLEY +"gnome10","path");
add_property("no_undead", 1);
add_clone(NPC+"wolf.c",2);
}
void init()
{
   add_action("do_climb","climb");
   ::init();
}

int do_climb(string str)
{
   if(str == "up" || str == "cliff" || str == "ledge")
   {
      write("You climb up this very steep cliff with considerable "
         "difficulty, and manage to impress yourself with your climbing skills.\n");
      this_player()->move(VALLEY+"ledge");
      this_player()->look_me();
      return 1;
      }
   else
   {
      write("Climb where?\n");
      return 1;
   }
}
