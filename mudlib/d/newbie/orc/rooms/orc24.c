#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
set_long("\n   Realm of the Orc:  Tunnel.\n\n"
         "     The temperature has fallen several degrees.  A cold "
         "breeze flows "
"through the tunnel like a river. The walls are wet with "
"condensation which gives the walls a sparkling effect.\n\n");

add_item("condensation", " \n\n"
"  HEY!!! YOU ARE AN ORC!! you have NO idea what the hell "
"condensation is!!! but if you must know, get a dictionary! \n");

add_item(({"walls", "wall", "tunnel"}),
"  The tunnel's walls are wet which causes the light waves in the tunnel to refract and mess up your vision. You suddenly have a greater dislike for physics.\n\n");

add_exit("west",CASTLE +"orc27","path");
add_exit("northeast",CASTLE +"orc22","path");
}
