//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_clone(NPC+"ciudad_pobre.c",2); 
   add_exit("sudoeste",CIUDAD"call1_2.c","standard");
   add_exit("sudeste",CIUDAD"call1_3.c","standard");
}