//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("oeste",CIUDAD"mnorte_6.c","standard");
   add_exit("sur",CIUDAD"mnorte_12.c","standard");
   add_exit("abajo",CIUDAD"ext_norte_24.c","standard");
}
