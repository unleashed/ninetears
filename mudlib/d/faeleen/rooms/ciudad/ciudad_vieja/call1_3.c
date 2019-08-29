//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("este",CIUDAD"cnorte_2.c","standard");
   add_exit("noroeste",CIUDAD"call1_0.c","standard");
}