//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("oeste",CIUDAD"msur_16.c","standard");
   add_exit("sudeste",CIUDAD"msur_18.c","standard");
   add_exit("abajo",CIUDAD"ext_sur_17.c","standard");
}