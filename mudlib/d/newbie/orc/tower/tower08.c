#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup() {
set_short("Realm of the Orc:  Top of Tower");
set_light(40);
   set_long("\n   Realm of the Orc:  Top of Tower.\n\n"
            "     This is a room that is at the very top of the tower.  "
            "It looks as if the Orcs are currently using it as a "
            "torture area, but this once was likely a room used as a "
            "temple.  There is a small staircase leading down.  "
            "\n\n");
add_item(({"temple","room","walls","wall","floor","ceiling"}),"\n"
"  The room was once used by some cult of the humans. "
"Since your knowledge of human culture is limited only to "
"the taste of humans, you know and understand little of your "
"surroundings.\n");
 add_clone(CHAR+"guard.c",2);
 add_clone(CHAR+"pris01.c",1);
add_exit("down",TOWER +"tower07","room");
}
