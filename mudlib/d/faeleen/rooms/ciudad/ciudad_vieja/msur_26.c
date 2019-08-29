//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("oeste",CIUDAD"msur_25.c","standard");
   add_exit("noreste",CIUDAD"msur_27.c","standard");
   add_exit("abajo",CIUDAD"ext_sur_26.c","standard");
}