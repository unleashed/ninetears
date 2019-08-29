//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();
   day_clone(NPC+"ciudad.c",random(2)); 
   add_exit("noroeste",CIUDAD"mercado_10.c","standard");   
   add_exit("noreste",CIUDAD"mercado_12.c","standard");   
   add_exit("sur",CIUDAD"jardin_1.c","standard");   
   add_exit("este",CIUDAD"jardin_19.c","standard");   
}
