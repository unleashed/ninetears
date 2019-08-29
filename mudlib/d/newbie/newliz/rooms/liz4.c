#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Lizard's Island:  Beach\n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Lizard's Island:  Beach\n\n"
      "     This is a section of the beach that is partially covered with thick, lush "
      "vegetation which penetrates to the base of the mountains on the backside of the "
      "island.  You can see sandy beaches to the South as well as the sound of the "
      "ocean crashing against rocks.  To the Northeast, the vegetation continues "
      "and wildlife can be heard all around.  "
      "\n\n");

    add_item("shells","These shells are common all over the island and are frail to "
      "the touch.\n");
    add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
      "as yourself.\n");
    add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
      "to the touch of your feet.\n");
    add_feel(({"foilage","trees","jungle"}),"The majority of these plants have "
      "relatively fragile leaves to the touch and thick trunks to lock in valuable "
      "moisture.\n");
    add_sound("wildlife","Although the noise seems to merger into chatter, you can "
      "distinctly make out some monkeys, parrots, and some other, grunting, sounds.\n");
    add_sound(({"waves","beach","ocean"}),"The ocean's waves make a rythmic, gentle "
      "sound of water impacting on rocks lining the beach and then on the sand, itself.\n");

    add_exit("south",ROOMS+"liz3.c","path");
    add_exit("northeast",ROOMS+"liz6.c","path");
}


