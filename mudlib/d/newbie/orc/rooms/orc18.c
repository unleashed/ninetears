#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
   set_long("\n   Realm of the Orc:  Tunnel.\n\n"
   "You are grateful for the faint glow from the slime on the walls, as you now "
   "know where the dripping water goes, a cold breeze blows up from the large "
   "hole in the floor here. A statue of an orc with one hand upraised in "
   "apparent warning stands each side of the hole. Fortunately , there's "
   "a narrow track round the edge. "
   "\n");
   add_item(({"statue","statues"}),"The statues face away from the hole "
   "and appear somewhat beat up. A tattered length of rope hangs from the "
   "upraised arm of one statue.\n");
   add_item("hole","A cold stinking draft blows up from the hole, a faint "
   "echo gives some idea of it's depth.\n");
   add_item(({"rope","arm"}),"The arm of the statue supports a small "
              "rope.  The rope extends downward through the hole, "
              "leading into blackness.  "
              "\n");
   add_sound("echo","The echo indicates that the hole is at least 20 feet deep, with a large open space at the bottom.\n");
add_exit("south",CASTLE +"orc20","door");
add_exit("north",CASTLE +"orc14","door");
}
void init()
{
   ::init();
   add_action("do_climb","climb");
}
int do_climb(string str)
{
   if(str == "down" || str == "rope") 
      {
            write("You slowly climb down the rope, lowering yourself "
                  "into the blackness of the hole.  You finally reach the "
                  "bottom and see:  \n");
this_player()->move("/d/newbie/orc/dungeon/dungeon13");
            this_player()->look_me();
            return 1;
         }
      else
      {
         write("Climb what?\n");
         return 1;
      }
}
