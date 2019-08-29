// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte bordeando "
   "una gran roca de material granitico, al sur el real se desvia mientras "
   "se dirige hacia las colinas de Ostigurth, al este y al noreste observas "
   "la antigua senda que comunicaba ambas ciudades.\n");
add_exit("norte",    REAL2+"real_b_18","road");
 add_exit("sur", REAL2+"real_b_16","road");
   add_exit("este",     CAMINO+"s81.c", "path");
   add_exit("noreste",  CAMINO+"s79.c", "path");
   set_light(65);
   crea_bichos();
}
