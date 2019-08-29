//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("norte",CIUDAD"mnorte_0.c","standard");
   add_exit("sur",CIUDAD"mnorte_13.c","standard");
}
