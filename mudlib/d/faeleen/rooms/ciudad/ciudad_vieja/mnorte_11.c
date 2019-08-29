//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("oeste",CIUDAD"mnorte_10.c","standard");
   add_exit("noreste",CIUDAD"mnorte_4.c","standard");
   add_exit("abajo",CIUDAD"ext_norte_28.c","standard");
}
