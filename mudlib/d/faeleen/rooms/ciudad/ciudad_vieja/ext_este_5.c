//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sur",CIUDAD"ext_este_4.c","standard");
   add_exit("norte",CIUDAD"ext_este_6.c","standard");
   add_exit("arriba",CIUDAD"meste_5.c","standard");
}