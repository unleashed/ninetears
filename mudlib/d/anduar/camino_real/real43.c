// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En las cercanias observas como "
   "empiezan los cultivos del poblado de Eloras, un pequenyo poblado en el "
   "cual, cualquier forrastero es bienvenido, por todos o por todas.");
   add_exit("norte"   ,REAL"real44.c","road");
   add_exit("southwest"     ,REAL"real42.c","road");
   set_light(65);
   crea_bichos();
}
