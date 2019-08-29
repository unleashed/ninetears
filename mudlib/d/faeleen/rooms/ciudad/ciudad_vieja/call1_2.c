//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_exit("noreste",CIUDAD"call1_0.c","standard");
   add_exit("oeste",CIUDAD"call1_1.c","standard");
   add_exit("sur",CIUDAD"call1_4.c","standard");
}