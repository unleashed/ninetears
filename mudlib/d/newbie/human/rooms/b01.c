#include "path.h"
inherit HAVMAND+"beach.c";
object rodion;
void setup()
{

   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   This is the northernmost part of the beach. The white sand stretches "
    "to the south, while to the north are rocks. The deep blue of the sea "
    "looks very inviting, but the sight of fins in the water puts you off "
    "the idea of swimming."
    "\n\n");
    add_item("rocks","Sharp volcanic rocks, you will have to be careful "
    "if you want to explore them.\n");
    add_item(({"fin","fins"}),"Dark, black fins swimming to and fro a little "
    "way from the shore, you can only assume they are attached to some sort "
    "of marine animal, probably maneating... You don't really want to take "
    "a closer look.\n");

   add_clone(CHARS+"rodion",1);
}
void init()
{
    add_exit("north",HAVMAND+"r04.c","path");
    add_exit("south",HAVMAND+"b02.c","path");
    add_exit("west",HAVMAND+"j17.c","path");

    ::init();
}
void reset()
{
   if(!rodion)
{
      rodion = clone_object(CHARS+"rodion");
   rodion->move(this_object());
   }
}
