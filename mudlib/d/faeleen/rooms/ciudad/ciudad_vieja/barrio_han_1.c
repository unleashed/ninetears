//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",3); 
   add_exit("oeste",CIUDAD"barrio_han_0.c","standard");
   add_exit("este",CIUDAD"barrio_han_2.c","standard");
   add_exit("sudeste",CIUDAD"barrio_han_6.c","standard");
}
