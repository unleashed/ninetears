//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("noroeste",CIUDAD"msur_17.c","standard");
   add_exit("sudeste",CIUDAD"msur_19.c","standard");
}