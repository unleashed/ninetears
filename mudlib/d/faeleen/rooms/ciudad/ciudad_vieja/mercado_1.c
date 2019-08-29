//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(1)); 
   add_exit("noreste",CIUDAD"mercado_0.c","standard");
   add_exit("sudoeste",CIUDAD"mercado_4.c","standard");
   add_exit("sudeste",CIUDAD"mercado_5.c","standard");
}
