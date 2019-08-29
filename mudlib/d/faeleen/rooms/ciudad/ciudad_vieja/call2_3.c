///Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_clone(NPC+"ciudad_pobre.c",random(2)); 
   add_exit("oeste",CIUDAD"call2_2.c","standard");
   add_exit("sur",CIUDAD"call2_5.c","standard");
   
}