// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, A lo lejos al norte empiezas a "
   "observar las colinas del poblado de Eloras, un pequenyo poblado situado "
   "casi a mitad de camino entre anduar y dendara.");
   add_exit("norte"   ,REAL"real36.c","road");
   add_exit("sur"     ,REAL"real34.c","road");
   set_light(65);
   crea_bichos();
}