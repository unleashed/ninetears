// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Al norte observas como la calzada "
   "entra en un inmenso puente de piedra que cruza sobre el rio Urzabalgai, "
   "el unico rio que atraviesa estas desoladas tierras en las cuales hasta "
   "la ultima gota.");
   add_exit("norte"   ,REAL"real15.c","road");
   add_exit("southwest"     ,REAL"real13.c","road");
   set_light(65);
   crea_bichos();
}
