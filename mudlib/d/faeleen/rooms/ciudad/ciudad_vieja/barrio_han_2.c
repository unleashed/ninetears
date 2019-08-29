//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_han();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("oeste",CIUDAD"barrio_han_1.c","standard");
   add_exit("pafuera","CIUDAD/","standard");
   add_exit("este",CIUDAD"barrio_han_3.c","standard");
}
