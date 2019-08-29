//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudoeste",CIUDAD"ext_norte_28.c","standard");
   add_exit("este",CIUDAD"ext_norte_26.c","standard");
}