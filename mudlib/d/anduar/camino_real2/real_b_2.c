// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la Calzada llega a un cruce, en el "
   "cual, hacia el suroeste se dirige a las colinas de Ostigurth, hacia el "
   "noroeste se adentra en el viejo camino y hacia el norte se dirige hacia "
   "dendara.\n");
   add_exit("norte",    REAL2+"real_b_3", "plain");
   add_exit("sudoeste", REAL2+"real_b_1.c","road");
   add_exit("noroeste", SENDA+"s64", "plain");
   set_light(65);
   crea_bichos();
}
