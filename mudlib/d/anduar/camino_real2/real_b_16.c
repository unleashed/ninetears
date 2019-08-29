// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte bordeando "
   "una gran roca de material granitico, al sur el real se desvia mientras "
   "se dirige hacia las colinas de Ostigurth.\n");
   add_exit("norte",    REAL2+"real_b_17","road");
   add_exit("sudoeste", REAL2+"real_b_15","road");
   set_light(65);
   crea_bichos();
}
