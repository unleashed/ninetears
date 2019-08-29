//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("norte",CIUDAD"mnorte_14.c","standard");
   add_exit("sudeste",CIUDAD"mnorte_27.c","standard");
}
