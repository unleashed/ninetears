// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige hacia el noreste "
   "dejando al oeste una gran roca de material granitico, al sur el real "
 "forma una gran recta mientras se dirige hacia las colinas de Ostigurth.\n");
   add_exit("noreste", REAL2+"real_b_16","road");
   add_exit("sur",     REAL2+"real_b_14","road");
   set_light(65);
   crea_bichos();
}
