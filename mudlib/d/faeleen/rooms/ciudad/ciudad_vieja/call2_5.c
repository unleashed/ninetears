///Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_clone(NPC+"ciudad_pobre.c",random(1)); 
   add_exit("norte",CIUDAD"call2_3.c","standard");
   
}