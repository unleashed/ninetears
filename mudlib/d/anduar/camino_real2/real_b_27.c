// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, parece ser que para ahorrar platinos los "
   "constructores decidieron usar en este tramo la antigua senda ya que la "
   "sigue sin desviarse lo mas minimo, aunque hay que reconocer que tampoco "
   "habria mejor sitio para seguir la ruta en esta zona.\n");
   add_exit("oeste",   REAL2+"real_b_28","road");
   add_exit("sudeste", REAL2+"real_b_26","road");
   set_light(65);
   crea_bichos();
}
