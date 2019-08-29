//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("oeste",CIUDAD"puerta_norte.c","standard");
   add_exit("noreste",CIUDAD"ext_norte_27.c","standard");
   add_exit("arriba",CIUDAD"mnorte_11.c","standard");
}