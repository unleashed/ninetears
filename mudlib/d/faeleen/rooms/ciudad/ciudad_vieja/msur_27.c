//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("sudoeste",CIUDAD"msur_26.c","standard");
   add_exit("noreste",CIUDAD"msur_28.c","standard");
}