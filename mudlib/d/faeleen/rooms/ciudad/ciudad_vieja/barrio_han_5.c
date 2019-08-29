//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",2); 
   add_exit("oeste",CIUDAD"barrio_han_4.c","standard");
   add_exit("norte",CIUDAD"barrio_han_0.c","standard");
   add_exit("sur",CIUDAD"barrio_han_8.c","standard");
   add_exit("sudoeste",CIUDAD"barrio_han_7.c","standard");
}
