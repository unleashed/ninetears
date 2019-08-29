//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("noroeste",CIUDAD"moeste_12.c","standard");
   add_exit("sudeste",CIUDAD"moeste_14.c","standard");
}