

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(3)); 
   add_exit("noroeste",CIUDAD"mercado_7.c","standard");
   add_exit("noreste",CIUDAD"mercado_8.c","standard");
   add_exit("sudeste",CIUDAD"jardin_0.c","standard");
    add_exit("este",CIUDAD"mercado_11.c","standard");
   add_exit("oeste",CIUDAD"calle_destino.c","standard");
}
