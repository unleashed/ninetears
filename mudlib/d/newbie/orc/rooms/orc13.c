#include "path.h"
inherit CASTLE+"baseroom.c";
 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Dining Room");
set_light(40);
   set_long("\n   Realm of the Orc:  Dining Room.\n\n"
            "     The dining path has been totally destroyed by the "
            "invaders.  It looks as if there was a major fight right "
            "here in this path.  The enormous table and the chairs "
            "are broken and now aren't much more than firewood.  The "
            "walls are covered with blood stains and chink marks made "
            "by a sword or axe.  The floor is littered with various "
            "bones and broken weapons.  The main hallway is to the "
            "north while more of the dining path is to the west.  "
            "\n\n");
   add_item(({"table","chair","firewood"}),"  The table and chairs "
       "seem to have been victims of the battle.  There is not much "
       "of them and cannot be of any use except for firewood.\n");
   add_item(({"floor","bone","weapon"}),"  The floor serves as a final "
       "resting place for those thad died in battle and their broken "
       "weapons.\n");
   add_item(({"wall","blood","stain","chink","marks"}),"  The walls "
       "seem to indicate the severity of the battle.  There is an "
       "incredible amount of blood sploched upon the wall and there "
       "are marks where a weapon bit into the wall all over the "
       "place.\n");
add_exit("west",CASTLE +"orc12","path");
add_exit("north",CASTLE +"orc07","path");
}
 
