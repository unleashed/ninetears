//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("norte",CIUDAD"ext_oeste_15.c","standard");
   add_exit("sudeste",CIUDAD"ext_sur_0.c","standard");
}