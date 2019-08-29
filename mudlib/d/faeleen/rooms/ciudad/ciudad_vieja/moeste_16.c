//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("norte",CIUDAD"moeste_15.c","standard");
   add_exit("sudeste",CIUDAD"msur_0.c","standard");
}