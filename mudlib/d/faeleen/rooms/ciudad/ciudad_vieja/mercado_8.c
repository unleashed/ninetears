//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(3)); 
   add_exit("sudoeste",CIUDAD"mercado_10.c","standard");
   add_exit("sudeste",CIUDAD"mercado_12.c","standard");
   add_exit("norte",CIUDAD"mercado_5.c","standard");   
}
