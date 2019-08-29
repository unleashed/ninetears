//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudeste",CIUDAD"ext_este_10.c","standard");
   add_exit("noroeste",CIUDAD"ext_este_12.c","standard");
}