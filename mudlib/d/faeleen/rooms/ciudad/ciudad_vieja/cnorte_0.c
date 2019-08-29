//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   cnorte();
   add_exit("norte",CIUDAD"puerta_norte.c","standard");
   add_exit("dentro",CIUDAD"ayuntamiento.c","door");
   add_exit("sur",CIUDAD"cnorte_1.c","standard");
}