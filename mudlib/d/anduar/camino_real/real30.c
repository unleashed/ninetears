// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Ante ti el rio Urzabalgai, provoca "
   "que los mercaderes tengan que tapar los oidos de sus monturas, ya que "
   "cualquier criatura por grande que sea podria ser hecha pedazos por este "
   "rio.");
   add_exit("oeste"   ,REAL"real31.c","road");
   add_exit("southeast"     ,REAL"real29.c","road");
   set_light(65);
   crea_bichos();
}
