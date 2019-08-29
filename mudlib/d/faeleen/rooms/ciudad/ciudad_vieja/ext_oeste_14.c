//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("noroeste",CIUDAD"ext_oeste_13.c","standard");
   add_exit("sur",CIUDAD"ext_oeste_15.c","standard");
}