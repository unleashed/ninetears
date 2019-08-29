//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(2)); 
   add_exit("oeste",CIUDAD"mercado_10.c","standard");   
}
