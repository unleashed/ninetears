#include "path.h"
inherit CASTLE+"baseroom.c";
 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
set_long ("\n    Realm of the Orc:  Tunnel.\n\n"
   "     The thing you notice first here is a faint and sourceless glow "
   "from the northeast. Other than that, and a cold breeze from somewhere, "
   "there isn't a lot to notice, it's dark, damp, and generally miserable right here. "
   "\n\n");


add_property("no_undead",1);
add_feel(({"wind","breeze"}),"The breeze seems to come from the north,\n");
add_item("glow", " \n"
" A light hue of yellow seems to be emanating from the northeast.\n");
add_exit("southwest",CASTLE +"orc24","path");
add_exit("northeast",CASTLE +"orc20","path");
}


