// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, en este lugar parece ser que los "
   "encargados de hacer el camino decidieron que para que la velocidad de "
   "las mercancias no se viese reducida lo mejor era atravesar la colina "
   "ya que una brecha atraviesa la misma y por ella penetra el camino.\n");
   add_exit("noreste"   ,REAL+"real4.c","road");
   add_exit("southwest"   ,REAL+"real2.c","road");
   set_light(65);
   crea_bichos();
}