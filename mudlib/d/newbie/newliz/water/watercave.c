inherit "/std/room";
#include "path.h"

void setup()
{
set_light(65);
set_short("Lizard Domain:  Underwater cave\n\n");
set_long("Lizard Domain:  Underwater cave\n"
"     In the darkness of this room, you can just see enough to realize that "
"this place has been formed by years of wave actions.  The walls are made of worn "
"volcanic rock and the constant current coming through the opening makes exiting "
"a little difficult.  Scattered in pieces are the remains of another lizard man.  "
"appearantly, he either didn't have the elder's spell or dove head-first into "
"the rocks that surround the beach.  "
"\n\n");

add_item("rocks","The rocks of this cave are primarily shale and volcanic in "
"their nature.  Both types are VERY sharp to the touch.\n");
add_feel(({"rocks","shale","volcanic rock","volcanic"}),"You decide against "
"grasping the rock after realizing just how sharp it is.\n");
add_feel("walls","The walls are smooth to the touch and are well worn.\n");
add_item("walls","The walls are made of worn-down volcanic rock and form a near "
"perfect circular indentation within this rock.\n");
add_item(({"remains","skeleton","lizardman","lizard man","lizard","man"}),"This "
"skeleton is all that remains of a once proud lizard warrior.  The remains are half "
"buried in the sand and you decide that a search might turn up something useful.\n");
add_item("current","The current is just strong enough to keep thing swept into the "
"cave here in place, but weak enough to allow you to leave when you so choose.\n");

add_exit("out",WATER+"water9.c","path");
}
