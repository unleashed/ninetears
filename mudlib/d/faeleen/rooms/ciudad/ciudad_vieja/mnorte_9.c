//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("noroeste",CIUDAD"mnorte_3.c","standard");
   add_exit("este",CIUDAD"mnorte_10.c","standard");
   add_exit("abajo",CIUDAD"ext_norte_1.c","standard");
}
