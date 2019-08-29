//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("oeste",CIUDAD"mnorte_19.c","standard");
   add_exit("este",CIUDAD"mnorte_21.c","standard");
}
