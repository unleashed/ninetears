//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("este",CIUDAD"barrio_han_5.c","standard");
   add_exit("sudeste",CIUDAD"barrio_han_8.c","standard");
   add_exit("sur",CIUDAD"barrio_han_7.c","standard");
}
