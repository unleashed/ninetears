//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("este",CIUDAD"puerta_norte.c","standard");
   add_exit("noroeste",CIUDAD"ext_norte_1.c","standard");
}
