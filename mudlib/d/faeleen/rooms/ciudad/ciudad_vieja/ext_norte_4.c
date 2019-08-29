//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sur",CIUDAD"ext_norte_5.c","standard");
   add_exit("este",CIUDAD"ext_norte_3.c","standard");
   add_exit("arriba",CIUDAD"mnorte_0.c","standard");
}