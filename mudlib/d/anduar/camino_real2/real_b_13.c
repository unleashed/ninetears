// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, hacia el sur en el alto de las colinas de "
   "Ostigurth observas una torre negra, hacia el sur el camino continua hasta "
   "un cruce de caminos mientras al norte continua en una gran recta.\n");
   add_exit("norte", REAL2+"real_b_14","road");
   add_exit("sur",   REAL2+"real_b_12","road");
   set_light(65);
   crea_bichos();
}
