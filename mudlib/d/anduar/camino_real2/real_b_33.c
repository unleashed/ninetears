// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte por en "
   "interior de un canyon tallado en la roca, para acortar el trayecto lo "
   "maximo posible, en lo alto de la misma se pueden observar restos de algun "
   "ave muerta.\n");
   add_exit("norte",   REAL2+"real_b_34","road");
   add_exit("sur",     REAL2+"real_b_32","road");
   set_light(45);
   add_item("ave","los restos de algun pajaro que no logras identificar por "
   "su altura");
   crea_bichos();
}
