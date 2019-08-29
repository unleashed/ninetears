inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
   set_long("Macedonia:  Shadow Valley\n\n"
            "   You are walking along the banks of the Gnude "
            "River.  Directly east are the Whispering Woods.  "
            "Across the river is a large mountain range.  Far "
            "to the south you can see what looks to be a large "
            "cliff which helps to protect Shadow Valley from "
            "invasion.  "
            "\n\n");
add_item(({"bank","banks"}),"This bank is rather bare from plants.  "
           "This is because the river is know to flood quite "
           "quite often and wash the land clear.\n");
add_item("cliff","Far to your south you can make out a huge cliff.  "
         "Since you are pretty far away, you are not sure "
         "exactlly how steep this cliff is, but it looks impossible "
         "to climb.\n");
add_item(({"mountain","range","mountain range"}),"Far too the "     
           "distance you can see the Mithril Mountains.  The "
           "base of the mountains in pretty clear but the peaks "
           "are somewhat covered by the clouds.\n");
add_item(({"woodland area","area","woods"}),"This area is overgrown "
           "with various trees and shrubs.  You are worried by the "
           "sounds, but your curiosity is growing faster than your "
           "fear.\n");
add_item(({"river","gnude river","gnude"}),"This is the gentle "
          "flowing Gnude River.  Although it is so gentle, it is "
          "too deep wo wade in and to wide to swim across\n");
add_clone(NPC+"owl.c",1);
add_clone(NPC+"wolf.c",3);
add_exit("south",VALLEY +"gnome16","path");
add_exit("north",VALLEY +"gnome03","path");
add_property("no_undead", 1);
}
