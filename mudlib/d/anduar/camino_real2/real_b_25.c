// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte dejando al "
   "sudeste una colina en la cual crece la tipica vegetacion de Dendara y de "
   "las laderas de la misma viene la vieja senda que unia las 2 ciudades.\n");
 add_exit("norte",   REAL2+"real_b_26.c","road");
   add_exit("sur",     REAL2+"real_b_24","road");
   add_exit("sudeste", "/d/dendara/rooms/camino/s49","road");
   set_light(65);
   crea_bichos();
}
