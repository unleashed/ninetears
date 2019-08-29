#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "You are walking along a dirt track which was made so that supplies could "
    "be taken from the small dock to your west to the village nestling below "
    "the castle wall. It doesn't seem to have had a lot of use lately as you "
    "can see small clumps of grass starting to grow in the deep ruts in the "
    "middle of the track. Impenetrable jungle looms to the north, and the "
    "road continues east. "
    "\n\n");
    add_item("dock","A little pier sits in the sea to the west. From here it "
    "looks badly in need of repair, and doesn't seem to have been used for "
    "some time.\n");
    add_item("village","A group og grotty little hovels beside a castle wall, "
    "you assume it could be called a village, though it seems mainly deserted "
    "now.\n");
    add_item(({"grass","clumps"}),"Bright green clumps of grass, they seem to "
    "be one of the few things thriving here.\n");
    add_item("jungle","A tangle of huge trees growing closely together, there "
    "is no way you could force your way through from here.\n");

}
void init()
{
   add_exit("dock",HAVMAND+"d00.c","path");
    add_exit("east",HAVMAND+"t02.c","path");

    ::init();
}
