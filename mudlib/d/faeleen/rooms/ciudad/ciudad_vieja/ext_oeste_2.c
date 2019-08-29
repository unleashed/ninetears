//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("noreste",CIUDAD"ext_oeste_1.c","standard");
   add_exit("sur",CIUDAD"ext_oeste_3.c","standard");
   add_exit("arriba",CIUDAD"moeste_2.c","standard");
}