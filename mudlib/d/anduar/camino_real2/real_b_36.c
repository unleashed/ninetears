// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte por en "
   "interior de un canyon tallado en la roca, para acortar el trayecto lo "
   "maximo posible, un poco al sur parece estar el centro de la colina.\n");
   add_exit("norte",   REAL2+"real_b_37","road");
   add_exit("sudeste", REAL2+"real_b_35","road");
   set_light(55);
   crea_bichos();
}
