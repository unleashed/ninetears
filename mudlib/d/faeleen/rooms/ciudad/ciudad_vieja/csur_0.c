//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   csur();
   day_clone(NPC"ciudad.c",random(1));
   add_exit("norte",CIUDAD"jardin_6.c","standard");
   add_exit("sur",CIUDAD"csur_1.c","standard");
}