// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige hacia el noroeste, "
   "bordeado por una hilera de arboles, a ambos lados de la calzada una "
   "canalizacion lleva el agua que riega a los mismos, dedicados a proteger "
   "al viajero del ardiente sol, mientras el camino se aleja de una colina "
   "que en tiempos pasados habia sido un obstaculo.\n");
   add_exit("noroeste", REAL2+"real_b_42","road");
   add_exit("sudeste",  REAL2+"real_b_40","road");
   set_light(65);
   crea_bichos();
}
