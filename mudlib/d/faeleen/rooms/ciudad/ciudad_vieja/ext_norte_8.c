//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("noreste",CIUDAD"ext_norte_7.c","standard");
   add_exit("oeste",CIUDAD"ext_norte_9.c","standard");
   add_exit("arriba",CIUDAD"mnorte_26.c","standard");
}