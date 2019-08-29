//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(3)); 
   add_exit("noroeste",CIUDAD"mercado_0.c","standard");
   add_exit("sudoeste",CIUDAD"mercado_5.c","standard");
   add_exit("sudeste",CIUDAD"mercado_6.c","standard");
   add_exit("oeste",CIUDAD"mercado_2.c","standard");
}
