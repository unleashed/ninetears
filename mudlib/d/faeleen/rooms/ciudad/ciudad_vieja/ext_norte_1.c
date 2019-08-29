//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudeste",CIUDAD"ext_norte_0.c","standard");
   add_exit("oeste",CIUDAD"ext_norte_2.c","standard");
   add_exit("arriba",CIUDAD"mnorte_9.c","standard");
}