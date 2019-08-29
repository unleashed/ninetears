// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, el suelo a diferencia de la vieja "
   "ruta esta perfectamente empedrado, con amplios sumideros a los lados que "
   "evitan que el mismo se llene de barro y que permiten ir a mucha mas "
   "velocidad y cada cierto tiempo hay unas curiosas marcas en los lados.\n");
   add_exit("este"   ,REAL+"real2.c","road");
   add_exit("sur"   ,REAL+"real0.c","road");
   set_light(65);
   crea_bichos();
}
