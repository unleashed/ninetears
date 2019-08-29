#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Upper Landing");
set_light(40);
   set_long("\n   Realm of the Orc:  Upper Landing.\n\n"
            "     You are standing at the top of the staircase on the "
            "upper landing.  The curved walls here lead right up to "
            "the ceiling.  There is a small room to the southeast "
            "through a badly damaged doorway.  The walls and ceiling "
            "are damaged as well as splattered with dried, flaking "
            "blood.  You can hear strange noises above you and what "
            "sounds like a muffled scream.  "
            "\n\n");
add_item("blood","\n"
"  The blood is dark with age and is caked on in several areas.\n");
add_sound(({"scream","muffle scream","noise","noises"}),"\n"
"  You hear,'TELL ME!!!' and then a whip-crack which is followed "
"by the source of the muffled sound....a scream!\n");
add_exit("southeast",TOWER +"tower06","room");
add_exit("down",TOWER +"tower04","room");
}
