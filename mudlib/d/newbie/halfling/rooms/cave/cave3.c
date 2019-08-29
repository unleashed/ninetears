inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("cave passage");
set_long("\nPassage in the Cave of Gloom.\n\n"
"     The cave of gloom is dimly lit by the glow of phospherescent moss. "+
"This section of the cave is roughly oval shape with very little to look at. "+
"It is rather unusual that there are no stalactites or stalagmites in this section. "+
"This may be a freak occurance, or it may just be that others have taken them out for some reason. "+
"With the smooth walls, ceiling, and floor this almost looks man made.  "
"There is a small passage to the north, as well as to the west. "
"\n\n");

set_light(100);
add_item("stalagtite","Stalagtites hang from the ceiling like thousands of large uvula.\n");
add_item("stalagmite","Stalagmites rise from the ground like thousands of jagged teeth.\n");
add_item("web","The webs on the wall are too high to reach, but they are quite beautiful.\n");
add_item("wall","The walls are made of a dark basalt.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the walls providing enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too slick to grab.\n");
add_exit("west",CAVES+"cave2.c","path");
add_exit("north",CAVES+"cave5.c","path");
add_clone(CHAR+"baby_spider.c",1);
}
