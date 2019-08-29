//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_exit("noreste",CIUDAD"barrio_han_6.c","standard");
   add_exit("este",CIUDAD"barrio_han_10.c","standard");
}
