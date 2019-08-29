#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
   set_long("\nIsle of Havmand : Track\n\n"
    "You are standing on a small dirt track outside one of the most "
    "miserable little hovels you have ever seen. Even by the low "
    "standards of this village, it is obvious that a strong gust of wind "
    "would almost be enough to knock it over. Surely the fact that it is built "
    "so close to the towering castle wall is the only reason it is still "
    "standing. "
    "\n\n");
    add_item("hovel","This miserable little dwelling place has most of its "
    "roof missing and big holes in its walls. You can almost see through it "
    "to the wall behind. \n");

}
void init()
{
    add_exit("north",HAVMAND+"t07.c","path");
    add_exit("south",HAVMAND+"t09.c","path");
    add_exit("west",HAVMAND+"v06.c","path");
    add_exit("east",HAVMAND+"j14.c","path");

    ::init();
}
