//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("oeste",CIUDAD"ext_sur_16.c","standard");
   add_exit("sudeste",CIUDAD"ext_sur_18.c","standard");
   add_exit("arriba",CIUDAD"msur_17.c","standard");
}