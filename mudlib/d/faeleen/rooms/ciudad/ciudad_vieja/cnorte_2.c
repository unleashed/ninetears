//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   cnorte();
   add_exit("norte",CIUDAD"cnorte_1.c","standard");
   add_exit("sur",CIUDAD"mercado_0.c","standard");
   add_exit("oeste",CIUDAD"call1_3.c","standard");
}