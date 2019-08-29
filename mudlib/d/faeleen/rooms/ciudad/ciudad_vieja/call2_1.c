///Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_clone(NPC+"ciudad_pobre.c",random(3)); 
   add_exit("sudoeste",CIUDAD"call2_2.c","standard");
   
}