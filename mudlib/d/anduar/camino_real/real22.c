// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Cada vez que te acercas mas y mas "
   "al cauce del rio Urzabalgai puedes ver la inmensidad del cauce de unos "
   "30 metros de un lado al otro con una corriente tan fuerte capaz de "
   "arrastrar a un caballo o bien de ahogar a cualquier persona que se caiga "
   "al mismo si no tiene cuidado.");
   add_exit("norte"   ,REAL"real23.c","road");
   add_exit("southwest"     ,REAL"real21.c","road");
   set_light(65);
   crea_bichos();
}
