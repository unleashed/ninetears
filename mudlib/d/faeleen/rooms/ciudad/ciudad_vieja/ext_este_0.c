//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudoeste",CIUDAD"ext_sur_28.c","standard");
   add_exit("norte",CIUDAD"ext_este_1.c","standard");
   add_exit("arriba",CIUDAD"meste_0.c","standard");
}