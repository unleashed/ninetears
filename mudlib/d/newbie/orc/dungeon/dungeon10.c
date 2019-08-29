#include "path.h"
inherit CASTLE+"baseroom.c";
void setup() { my_setup();
set_short("Realm of the Orc:  Dungeon Cell");
set_light(40);
set_long("\n   Realm of the Orc:  Dungeon Cell.\n\n"
         "     This is approximately a four by six cell.  The "
         "walls are made of stone and the are many sword marks "
         "which have been placed by the battle that "
         "have occurred here.  The only exit from here is a door "
         "to the north, but if you searched around the floor "
         "you might would be able to find an exit that a prisoner "
         "made to escape.\n\n");
add_item(("walls"),"\nThe walls in this rooms are made of extremely "
          "large boulders.  Looking at the boulders you notice "
          "cracks and scratches that appear to have been made by "
          "numerous battles that have occurred here.");
add_item(("door"),"\nThis is a large oak door.  With it's solid "
          "construction and the careful eye of guards, no "
          "prisoner would have been able to escape.");
add_item(("floor"),"\nLooking around the floor you see nothing "
          "except a few small stones around.  With your examination "
           "no exit is found.");
add_clone(CHAR+"dwarfpris.c",2);

add_exit("north",DUNGEON +"dungeon05","door");
}
 
 
