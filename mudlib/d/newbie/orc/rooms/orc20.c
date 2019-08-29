#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
set_long("\n   Realm of the Orc:  Tunnel.\n\n"
   "The tunnel slopes downwards a little to the north,and the sound of dripping "
   "water is brought to you on the cold breeze blowing along the tunnel. "
   "There's a slight phosphorescence from the walls that way as well. "
   "It doesn't make things any lighter really, just means that the few "
   "shadows fade out, making it even harder to see the rocks on the path. "
   "\n\n");
add_exit("north",CASTLE +"orc18","path");
add_exit("southwest",CASTLE +"orc22","path");
}
