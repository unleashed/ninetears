// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ven las colinas de "
   "Ostigurth, mientras hacia el norte sigue hacia Dendara, en las cercanias "
   "observas un cruce de caminos.\n");
   add_exit("norte",   REAL2+"real_b_11","plain");
   add_exit("sur", REAL2+"real_b_9","road");
   set_light(65);
   crea_bichos();
}
