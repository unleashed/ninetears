//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("norte",CIUDAD"ext_oeste_6.c","standard");
   add_exit("sur",CIUDAD"ext_oeste_8.c","standard");
}