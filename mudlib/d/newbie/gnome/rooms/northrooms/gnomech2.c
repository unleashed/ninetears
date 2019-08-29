inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  North of Shadow Valley");
   add_property("no_undead",1);
    set_light(40);
    set_long("Macedonia:  North of Shadow Valley\n\n"
      "You are far to the North of Shadow valley, in the wandering hills near the mountains.  "
      "To your south, you can barely make out some sort of a lake in the distance.  A stream wanders "
      "off into the forest to your West, and to either side of you is a dense forest."
      "\n\n");
    add_item(({"creek","stream","river","water"}),"This small stream seems to feed into the lake "
      "to the distant south.  It is fast flowing, and clouded from its turbulence.\n");
    add_item(({"lake","distant lake"}),"To your South, there seems to be a lake in the distance. \n");
    add_item(({"forest","woods"}),"From here, you can see the edge of "
      "the forest.  Due to its density, you can not see far "
      "into it.\n");
    add_item(({"mountain","range","mountain range","mountains"}),"Far to the "
      "distance you can see the Mithril Mountains.  The "
      "base of the mountains in pretty clear but the peaks "
      "are somewhat covered by the clouds.\n");
    add_exit("south",NORTHRMS +"gnomech1.c","path");
    add_exit("north",NORTHRMS +"gnomech3.c","path");
}
void init()
{
    add_action("do_drink","drink");
    ::init();
}
int do_drink(string str)
{
    write("You don't think that is a good idea to drink this water so soon after leaving the forest.\n");
    return 1;
}

