//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(1)); 
   add_exit("noroeste",CIUDAD"mercado_8.c","standard");
   add_exit("noreste",CIUDAD"mercado_9.c","standard");
   add_exit("sudoeste",CIUDAD"jardin_0.c","standard");
}
