#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Small Room");
set_light(40);
   set_long("\n   Realm of the Orc:  Small Room.\n\n"
            "     The battle seems to have been tremendous from the looks "
            "of this room.  The blood and gore that is splattered all "
            "over the walls and ceiling here only begins to reveal the "
            "horrible sight of war.  Bones are strewn all about from "
            "what would likely make up several complete skeletons, and "
            "a number of broken weapons are in various places among the "
            "bodies.  There is a badly damaged doorway that leads out "
            "onto the landing to the northwest.  "
            "\n\n");
   add_item(({"wall","ceiling"}),"  The walls and ceiling are "
       "are splattered with blood from the battle that occured here.  "
       "You notice that the blood is flaking off in several places, but "
       "strangely there is a large rectangular area where all of the "
       "blood is completely gone.  "
       "\n");
   add_item(({"rectangle","rectangular area","blood"}),"  The blood "
       "is flaking off all over the room but nowhere is it flaking off "
       "like the area on the eastern wall.  \n");
   add_item(({"eastern wall","east","east wall"}),"  There is a large "
       "area along this wall where the blood has flaked off.  It is "
       "shaped just like a door.  You might be able to push your way "
       "through. \n");
 add_item("bone","Broken bones left over from when the orcs took "
    "over this place. Must have been a hell of a fight here.\n");

add_exit("northwest",TOWER +"tower05","room");
}
void init()
{
   ::init();
   add_action("push_me","push");
}
int push_me(string str)
{
   if(str == "wall" || str == "door" || str == "rectangle")
      {
         write("The slightest push on this wall sends you into "
               "another place.\n");
         this_player()->move("/d/newbie/orc/tower/tower07.c");
         this_player()->look_me();
         return 1;
      }
   else
      {
         return 0;
      }
}
