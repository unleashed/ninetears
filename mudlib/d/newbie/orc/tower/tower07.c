#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Secret Passage");
set_light(40);
   set_long("\n   Realm of the Orc:  Secret Passage.\n\n"
            "     You are standing at the bottom of a small secret "
            "staircase.  You can hear strange sounds and muffled "
            "screams from above.  The stairs lead up and you can "
            "also go out to the small room.  "
            "\n\n");
add_sound(({"scream","sound","noise","muffled scream"}),"\n"
"  You hear, 'TELL ME!!!' then a whip-crack followed by a scream!\n");
add_item("staircase", " It looks like a staircase.\n");
add_exit("up",TOWER +"tower08","room");
add_exit("out",TOWER +"tower06","room");
}
