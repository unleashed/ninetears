#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     You have wandered into a section of the jungle which is renouned for its "
"increased danger.  The vegetation here seems to form a canopy strictly for the "
"purpose of keeping out the sunlight.  To the south, you can hear the crash of the "
"ocean against the beach.  To the North and Southwest, the path through the jungle "
"continues, though it seems to darken even further to the North.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_sound(({"beach","waves","ocean"}),"The waves are making a very relaxing, rythmic "
"sound as they gently pound upon the beach.  \n");
add_item("dark","The canopy of the forest maybe dark, here, but to the North, it "
"seems to allow even less light though the treetops.  \n");
add_item("sunlight","The sun is all but blocked out by the trees, here.\n");
add_item("trees","The trees of this jungle stand only about forty feet at their "
"tallest, but are still sufficient to block out the majority of the light reaching "
"the ground.  \n");

add_exit("southwest",ROOMS+"liz4.c","path");
add_exit("south",ROOMS+"liz5.c","path");
add_exit("north",ROOMS+"liz8.c","path");
}


