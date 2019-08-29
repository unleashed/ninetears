//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("oeste",CIUDAD"msur_2.c","standard");
   add_exit("noreste",CIUDAD"msur_4.c","standard");
}