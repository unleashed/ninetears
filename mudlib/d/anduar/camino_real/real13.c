// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En la distancia hacia el sur "
   "observas el gran complejo de Comellas una posada conocida a lo largo y "
   "ancho del mundo del cual dicen que es uno de los mas grandes cocineros "
   "de todas las eras.");
   add_exit("noreste"   ,REAL"real14.c","road");
   add_exit("sur"     ,REAL"real12.c","road");
   set_light(65);
   crea_bichos();
}
