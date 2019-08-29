// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, al norte el camino llega a un cruce que "
 "parece ser el del viejo camino, ahora casi abandonado, mientras que al sur "
   "se dirige hacia las colinas de Ostigurth.\n");
   add_exit("noreste", REAL2+"real_b_23","road");
   add_exit("sur",     REAL2+"real_b_21","road");
   set_light(65);
   crea_bichos();
}