// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras2.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, en las proximidades del poblado de "
   "Eloras, A ambos lados de la calzada observas unos campos de trigo, "
   "principal fuente de alimentacion del poblado.");
   add_exit("noreste"   ,REAL"real50.c","road");
   add_exit("sur"     ,REAL"real48.c","road");
   set_light(65);
   crea_bichos();
}