// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte por en "
   "interior de un canyon tallado en la roca, para acortar el trayecto lo "
   "maximo posible.\n");
   add_exit("norte",    REAL2"real_b_40.c","road");
   add_exit("este",     "/d/dendara/rooms/camino/s23","road");
   add_exit("sudoeste", REAL2+"real_b_38","road");
   set_light(65);
   crea_bichos();
}
