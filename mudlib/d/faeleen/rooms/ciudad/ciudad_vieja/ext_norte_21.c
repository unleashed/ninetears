//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("norte",CIUDAD"ext_norte_22.c","standard");
   add_exit("sudeste",CIUDAD"ext_norte_20.c","standard");
}