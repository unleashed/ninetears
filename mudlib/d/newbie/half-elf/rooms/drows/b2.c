//Ljen nov -96

inherit"/std/room";
#include "path.h"
object drow,rat;

void setup()
{
   set_light(50);

   set_short("Drow tunnel");

   set_long("As you venture deeper into this dark tunnels, you can"
            " see less. You can hear the water drip slowly down the"
            " walls of this tunnel, and you can also hear the rats"
            " sneak around. You have the most terrible feeling they are"
            " very big.. just wanting to have a bite of a small half-elf."
            " The presence of evil feels even stronger here, but it seems"
            " like it comes from the east somehow.. strange.. \n");

   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");

   add_clone(NPC+"drow.c",1);

   add_clone(NPC+"rat.c", 1);

   add_exit("west", DROWS+"a2.c", "path");

   add_exit("east", DROWS+"c2.c", "path");

   add_exit("south", DROWS+"b3.c", "path");

   add_exit("northeast", DROWS+"c1.c", "path");

}
