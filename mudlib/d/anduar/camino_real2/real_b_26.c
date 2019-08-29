// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al noroeste por encima de "
   "la antigua senda de Anduar a Dendara, al sur observas un cruce en el cual "
   "la antigua senda sigue su propia ruta mientras que el camino real sigue "
   "en linea casi recta hacia Anduar.\n");
   add_exit("noroeste", REAL2+"real_b_27","road");
   add_exit("sur",   REAL2+"real_b_25","road");
   set_light(65);
   crea_bichos();
}
