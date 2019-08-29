//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("oeste",CIUDAD"mnorte_9.c","standard");
   add_exit("este",CIUDAD"mnorte_11.c","standard");
}
