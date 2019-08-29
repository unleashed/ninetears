#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     Before you rises a massive underwater mountain.  This mountain, to the North "
"goes so far up that it breaches the surface.  Somehow, your nose must be working "
"underwater, because you can detect the foul aroma of sulfer around you.  The water "
"temperature has also shot up to a nearly uncomfortable level.  The only other "
"route you could take would be to the South.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"mountain","island","volcano"}),"The underwater mountain rises above "
"the surface of the ocean.  Normally, such a steep mountain would be difficult to "
"climb.  However, in the reduced gravity of the water, you decide it may just "
"be possible.\n");
add_item("sulfur","Although you cannot see the sulfur, you know it is all around you "
"because of its foul stench of rotting eggs.\n");
add_smell(({"sulfur","water","here","rotting eggs","eggs"}),"The sour smell of "
"rotting eggs is almost overwhelming.  Your head spins as you inhale deeply.\n");
add_item(({"rotting eggs","eggs"}),"No, I said it smelled like rotting eggs, not "
"that there were rotting eggs here.\n");
add_feel(({"water","heat","here"}),"The water temperature has shot up by about "
"30 degrees in the past fifty yards.  At the rate the temperature is climbing, "
"it will become untolerable in just a short distance to the North.\n");

add_exit("up",VOLCANO+"island1.c","path");
add_exit("south",WATER+"water13.c","path");
}


