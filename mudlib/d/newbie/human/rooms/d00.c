#include "path.h"
inherit "/std/outside";
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
   set_short("Isle of Havmand: Dock.");
   set_long("\nIsle of Havmand : Dock\n\n"
    "Originally, this small wooden dock was used for the loading and "
    "unloading of supplies for the castle and village, but it hasn't been "
    "used in a long time. Many of its planks are rotten and several of them "
    "have disappeared altogether. "
    "\n\n");
    set_night_long("\n   Isle of Havmand: Dock.\n"
    "Your footsteps sound loudly on the wooden planks of this small dock,"
    "but you have to be careful not to step into a hole where a plank has "
    "rotted away. The water below gleams softly in the darkness. "
    "\n\n");
    add_item(({"plank","planks"}),"Long flat bits of wood used to make this "
    "dock, many of them are rotten.\n");
    add_item("water","The sea is deep blue and laps against the supports of the dock.\n");
    add_smell("air","The air smells salty.\n");
add_item("dock","The dock is made of rotten wooden planks.\n");
    add_sound("footsteps","Your footsteps echo hollowly on the wooden planks.\n");

}
void init()
{
    add_exit("east",HAVMAND+"t01.c","path");

    ::init();
}
