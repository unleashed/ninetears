// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, al norte el camino parece desviarse hacia "
   "el este, acercandose al viejo camino, mientras las colinas de Ostigurth "
   "se observan en la lejania al final de una gran recta.\n");
   add_exit("norte", REAL2+"real_b_15","road");
   add_exit("sur",   REAL2+"real_b_13","road");
   set_light(65);
   crea_bichos();
}
