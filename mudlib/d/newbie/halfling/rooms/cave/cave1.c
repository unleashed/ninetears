inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("cave entrance");
set_long("\nCave of Gloom.\n\n"
"     The cave of gloom is dimly lit by the glow of phosphorescent moss. "+
"There is a distand chittering noise coming from somewhere inside the cave. It could "+
"be coming from anywhere because of the constant echoes. It is apparent that you are not alone. "+
"There are spider webs on the walls to the east, west, and broken gossamer strands "+
"to the north.\n\n");

set_light(100);
add_item("web","The webs on the wall are too high to reach, but they are quite beautiful.\n");
add_item("gossamer","This is a spider web that has been broken by movement of "+
"other halflings who have come here before you.\n");
add_item("wall","The walls are made of a dark basalt.\n");
add_item("moss","The phospherescent moss covers the cave in small patches "+
"imbedded into the walls providing enough light to see.\n");
add_feel("gossamer","The gossamer sticks to you. With some difficulty, you get it off your hand.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too slick to grab.\n");
add_exit("north",CAVES+"cave2.c","path");
add_exit("out",ROOMS+"half16.c","path");
add_clone(CHAR+"baby_spider.c",1);
}
