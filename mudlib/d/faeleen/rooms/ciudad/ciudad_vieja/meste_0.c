//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   meste();
   add_exit("sudoeste",CIUDAD"msur_28.c","standard");
   add_exit("norte",CIUDAD"meste_1.c","standard");
   add_exit("abajo",CIUDAD"ext_este_0.c","standard");
}