// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, hacia el sur en el alto de las colinas de "
   "Ostigurth observas una torre negra, hacia el sudeste el camino llega a un "
   "cruce de caminos mientras al norte se ve una gran recta.\n");
   add_exit("norte",   REAL2+"real_b_13","road");
   add_exit("sudeste", REAL2+"real_b_11","road");
   set_light(65);
   crea_bichos();
}
