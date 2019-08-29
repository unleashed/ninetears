//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("norte",CIUDAD"moeste_11.c","standard");
   add_exit("sudeste",CIUDAD"moeste_13.c","standard");
   add_exit("abajo",CIUDAD"ext_oeste_12.c","standard");
}