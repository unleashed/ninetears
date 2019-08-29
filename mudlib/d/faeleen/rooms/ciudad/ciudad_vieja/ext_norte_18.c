//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("oeste",CIUDAD"ext_norte_19.c","standard");
   add_exit("sudeste",CIUDAD"ext_este_14.c","standard");
   add_exit("arriba",CIUDAD"mnorte_29.c","standard");
}