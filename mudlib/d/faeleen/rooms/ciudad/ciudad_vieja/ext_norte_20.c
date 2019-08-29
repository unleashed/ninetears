//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("noroeste",CIUDAD"ext_norte_21.c","standard");
   add_exit("este",CIUDAD"ext_norte_19.c","standard");
}