//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(3)); 
   add_exit("noreste",CIUDAD"mercado_1.c","standard");
   add_exit("sur",CIUDAD"mercado_7.c","standard");   
}
