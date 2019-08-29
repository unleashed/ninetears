// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte bordeando "
   "una gran roca de material granitico, al sur la calzada llega a un cruce "
   "con la antigua ruta, mientras que al norte se desvia para esquivar un "
   "viejo arbol.\n");
   add_exit("noroeste",   REAL2+"real_b_20","road");
   add_exit("sur",     REAL2+"real_b_18","road");
   set_light(65);
   crea_bichos();
}