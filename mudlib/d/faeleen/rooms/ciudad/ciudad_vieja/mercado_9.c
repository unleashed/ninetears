//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(2)); 
   add_exit("norte",CIUDAD"mercado_6.c","standard");
   add_exit("sudoeste",CIUDAD"mercado_12.c","standard");   
}
