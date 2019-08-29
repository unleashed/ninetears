//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("norte",CIUDAD"mnorte_7.c","standard");
   add_exit("sur",CIUDAD"mnorte_14.c","standard");
}
