// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, La calzada aqui vuelve a tomar su "
   "rumbo hacia el norte para pasar por el cercano puente ahora visto con "
   "mas detalles parece no ser de origen humano, ya que grotescos gravados "
   "aparecen por todo el puente.");
   add_exit("northwest"   ,REAL"real20.c","road");
   add_exit("este"     ,REAL"real18.c","road");
   set_light(65);
   crea_bichos();
}