//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   meste();
   add_exit("sudeste",CIUDAD"meste_9.c","standard");
   add_exit("noroeste",CIUDAD"meste_11.c","standard");
}