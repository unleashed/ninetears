//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",2); 
   add_exit("noroeste",CIUDAD"barrio_han_1.c","standard");
   add_exit("sudoeste",CIUDAD"barrio_han_9.c","standard");
}
