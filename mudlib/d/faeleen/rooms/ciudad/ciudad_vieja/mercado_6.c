//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(2)); 
   add_exit("noroeste",CIUDAD"mercado_3.c","standard");
   add_exit("sur",CIUDAD"mercado_9.c","standard");   
}
