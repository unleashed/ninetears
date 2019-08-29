#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Volcanic Island:  Jungle");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Volcanic Island:  Jungle \n\n"
"     This is the NorthEasterly most point on this small, volcanic "
"island.  There is thick, sticky jungle surrounding you.  You can "
"also hear the ocean crashing against the cliffs below you, just "
"on the other side of the trees to the East.  The only routes "
"through the jungle which you can see are to the NorthWest and to "
"the SouthEast.  "
    "\n\n");

add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_item("jungle","The jungle is towering above you and the sounds of exotic "
"animals and fragrances of plants almost overwhelm your senses.  This island "
"is much different from your home island.  \n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_smell(({"fragrance","plants","flowers"}),"The smells of the plants and flowers "
"around you are all sweet and sugary in their scent.  It's a good thing that you "
"are not alergic to any kind of pollen.\n");
add_item("flowers","The flowers in this this area range in size and color, covering "
"the entire spectrum of what you have seen before, and then some.\n");
add_feel("flowers","The flowers are delicate and papery under your scaly touch.\n");
add_item("trees","The trees of this place reach much higher than those of your "
"home island.  You are thankful that you aren't required to shimmy up these trees "
"as you do at home to get coconuts for food.  \n");
add_item("pollen","%^GREEN%^ACHOO!!!%^RESET%^");
add_sound("ocean","The ocean is crashing far away from you.  It also "
"sounds like it is hitting quite a ways down, implying a cliff to "
"the East.\n");

add_exit("south",VOLCANO+"island6.c","path");
add_exit("northwest",VOLCANO+"island10.c","path");
}


