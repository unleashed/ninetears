#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Lizard's Island:  Beach\n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Lizard's Island:  Beach\n\n"
      "     The beach continues its arc in in toward the Northeast.  From here, you can "
      "also just make out an island in the distance, although the haze in the air "
      "makes it very difficult.  The sand here is also becoming more coarse to the "
      "touch.  The beach, itself continues to the Northeast and Southwest.  A second, "
      "smaller, path leads into the jungle to the North.  "
      "\n\n");

    add_item("shells","These shells are common all over the island and are frail to "
      "the touch.\n");
    add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
      "as yourself.\n");
    add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
      "to the touch of your feet.\n");
    add_item("island","The island is too far away to see clearly. \n");

    add_exit("southwest",ROOMS+"liz2.c","path");
    add_exit("northeast",ROOMS+"liz5.c","path");
    add_exit("north",ROOMS+"liz4.c","path");
}


