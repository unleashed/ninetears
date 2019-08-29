// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
  "Anduar a la ciudad de Dendara, estas al sur de una colina en la cual se "
  "divide en tres, al noroeste y noreste el camino pertenece a la vieja senda "
  "mientras que el tramo central pertenece al camino real.\n");

   add_exit("norte",    REAL2+"real_b_33","road");
   add_exit("sur", REAL2+"real_b_31","road");
   add_exit("noroeste", "/d/dendara/rooms/camino/s39.c", "path");
   add_exit("noreste",  "/d/dendara/rooms/camino/s40.c", "path");
   set_light(65);
   crea_bichos();
}
