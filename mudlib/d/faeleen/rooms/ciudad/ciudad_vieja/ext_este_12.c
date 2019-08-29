//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudeste",CIUDAD"ext_este_11.c","standard");
   add_exit("noroeste",CIUDAD"ext_este_13.c","standard");
}