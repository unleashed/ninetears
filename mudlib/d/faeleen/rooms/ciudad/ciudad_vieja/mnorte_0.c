//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("este",CIUDAD"mnorte_1.c","standard");
   add_exit("sur",CIUDAD"mnorte_8.c","standard");
   add_exit("abajo",CIUDAD"ext_norte_4.c","standard");
}
