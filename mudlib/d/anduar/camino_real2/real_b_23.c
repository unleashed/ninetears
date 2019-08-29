// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte trazando una "
 "gran recta, mientras que al sur el camino no para de describir curvas para "
   "esquivar diversos obstaculos naturales.\n");
   add_exit("norte",    REAL2+"real_b_24","road");
   add_exit("sudoeste", REAL2+"real_b_22","road");
   set_light(65);
   crea_bichos();
}