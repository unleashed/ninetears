inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("cave");
set_long("\nInside the Cave of Gloom.\n\n"
"The interior of the cave is wonderously large. It is filled with stalactites "+
"and stalagmites covered in phosphorescent moss. Water slowly drips down from "+
" the stalactites slowly forming the stalagmites over the centuries. Behind you, "+
"you can see more broken gossamer. To the north, you can see an opening in the "+
"cave with absolutely no webs around it. To the west are more webs. There is an opening to the east.\n\n");

set_light(100);
add_item("web","The webs on the wall to the west are filled with what looks like "+
"the remains of both animals and halflings.\n");
add_item("gossamer","This is a spider web that has been broken by movement of "+
"other halflings who have come here before you.\n");
add_item("stalactite","Stalactites hang from the ceiling like thousands of large uvula.\n");
add_item("stalagmite","Stalagmites rise from the ground like thousands of jagged teeth.\n");
add_item("wall","The walls are made of a dark basalt.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"all over the stalagtites and stalagmites providing enough light to see.\n");
add_taste("water","the water tastes full of sediment, but it is refreshing.\n");
add_feel("gossamer","The gossamer sticks to you. With some difficulty, you get it off your hand.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too slick to grab.\n");
add_exit("east",CAVES+"cave3.c","path");
add_exit("north",CAVES+"cave4.c","path");
add_exit("south",CAVES+"cave1.c","path");
add_clone(CHAR+"baby_spider.c",3);
}
