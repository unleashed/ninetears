//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("oeste",CIUDAD"msur_9.c","standard");
   add_exit("este",CIUDAD"msur_11.c","standard");
}