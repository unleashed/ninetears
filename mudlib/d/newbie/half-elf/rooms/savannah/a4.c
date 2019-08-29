// modified by Ljen okt -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_short("Path To Castle of the Green Sun - Main Entrance");
   set_long("You are standing at the entrance of the famous Castle of the "
            "Green Sun. The castle is, indeed, a big house.  The door is "
            "a heavy wooden gate and there are two small loopholes in each "
            "of the sides of it,  just above there is a symbol of the "
            "high heriarchy of the half-elven people.  From here you can see "
            "it is a low building, with only one level. There is also "
            "many windows.  To the east it opens a big "
            "plain, also called savannah.\n ");

    add_item("door", "A large gate, no enemies will get in here easy.\n");

    set_light(80);

    add_exit("in" ,  CAST+"f4.c" ,   "door");
    add_exit("east", SAVANNAH+"b4", "path");
}
