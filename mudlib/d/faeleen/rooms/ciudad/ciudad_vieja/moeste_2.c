//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("noreste",CIUDAD"moeste_1.c","standard");
   add_exit("sur",CIUDAD"moeste_3.c","standard");
   add_exit("abajo",CIUDAD"ext_oeste_2.c","standard");
}