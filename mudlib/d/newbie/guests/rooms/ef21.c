inherit "std/room";
 
#include "path.h"
void setup()
{
  //ef21.c
  set_light(70);
  set_short("Gnarlwood Forest");
  set_long("Gnarlwood Forest\n"
           "Wiry roots link and form cage-like walls around "
           "a spacious cavern.  Around you, you notice that the layers "
           "of dirt and rock meet here, forming sedimentary layers and "
           "establishing the end of the madness that was the forest.  "
           "Scrolls and tightly capped potions are placed carefully "
           "between the roots and in nooks in the wall; several symbols "
           "have been either scorched or blood-stained into the stone "
           "bottom.  The hair atop the bottom of your neck rises, whether "
           "you abhor the dark evil in this forest or admire it.\n");
  add_item(({"root","roots","walls","wall"}),
           "Dark black roots thicker than your forearm confine you in "
           "this cavern.  Your only exit is up; and even then, you are "
           "unsure if the forces here will allow you to leave.\n");
  add_item(({"rock","stone"}),
          "Deep brown limestone crumbles slightly from the pressure "
          "of the heavy soil above it.\n");
  add_item(({"dirt","soil"}),
          "You sigh in relief as you notice the soil ends and the rock "
          "begins.  Rock, at least, is something you would expect to see here "
          "far below the earth.\n");
  add_item(({"scroll","scrolls"}),
           "Tightly bound scrolls hide their words from you; they cannot, "
           "however, hide the deep crimson stains on their well-worn edges.\n");
  add_item(({"potion","potions","bottle","bottles"}),
             "Dark green and a glowing yellow fill many of the bottles.  "
             "Periodically, the liquid shudders as bubbles rise from the bottom.\n");
  add_item(({"symbol","symbols","bottom","floor"}),
             "You stare at the symbols etched into the ground below you, "
             "but the shapes seem to change before you are able to "
             "recognize them.  Your temples become hot and then begin "
             "to pound as you concentrate more intently; the symbols continue "
             "to elude you.\n");
 
   add_property("no_undead",1);
   add_exit("west",HERE+"con01","path");
  add_exit("east",HERE+"ef4","path");
   add_clone(NPCS+"daemon.c",1);
 
}

