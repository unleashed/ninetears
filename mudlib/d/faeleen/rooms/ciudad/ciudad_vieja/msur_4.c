//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("sudoeste",CIUDAD"msur_3.c","standard");
   add_exit("noreste",CIUDAD"msur_5.c","standard");
}