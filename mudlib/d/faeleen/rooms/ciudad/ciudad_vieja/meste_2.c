//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   meste();
   add_exit("sur",CIUDAD"meste_1.c","standard");
   add_exit("norte",CIUDAD"meste_3.c","standard");
}