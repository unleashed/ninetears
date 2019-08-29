//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mercado();
   day_clone(NPC+"mercado.c",random(4)); 
   add_exit("norte",CIUDAD"cnorte_2.c","standard");
   add_exit("este",CIUDAD"call2_4.c","standard");
   add_exit("sudoeste",CIUDAD"mercado_1.c","standard");
   add_exit("sudeste",CIUDAD"mercado_3.c","standard");
}
