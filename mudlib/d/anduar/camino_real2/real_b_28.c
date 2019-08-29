// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, en este tramo el camino se dirige otra vez "
   "hacia el norte, bordeando los diversos accidentes naturales de la zona, "
   "dirigiendose a un cruce delante de una pequenya colina.\n");
   add_exit("noroeste", REAL2+"real_b_29","road");
   add_exit("este",     REAL2+"real_b_27","road");
   set_light(65);
   crea_bichos();
}
