// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
  "Anduar a la ciudad de Dendara, tras esquivar un pequenyo accidente natural "
   "el camino vuelve a cambiar de direccion, dirigiendose a un cruce al sur "
   "de las colinas, en el cual el camino se divide en 3, 2 de los tramos "
   "pertenecen al camino antiguo y un tercero al nuevo.\n");
   add_exit("noreste", REAL2+"real_b_31","road");
   add_exit("sur",     REAL2+"real_b_29","road");
   set_light(65);
   crea_bichos();
}
