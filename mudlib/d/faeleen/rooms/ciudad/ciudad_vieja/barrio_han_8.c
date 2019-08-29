//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("oeste",CIUDAD"barrio_han_7.c","standard");
   add_exit("noroeste",CIUDAD"barrio_han_4.c","standard");
   add_exit("norte",CIUDAD"barrio_han_5.c","standard");
}
