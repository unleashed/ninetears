//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("este",CIUDAD"ext_norte_16.c","standard");
   add_exit("sudoeste",CIUDAD"ext_oeste_0.c","standard");
}