// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En este punto la calzada  transcurre "
   "por los pies de un precipicio de poca altura, por el aspecto de la roca "
   "del mismo, seguro que ha sido tallada por los enanos para permitir un "
   "minimo desnivel a los carruajes.");
   add_exit("noreste"   ,REAL"real43.c","road");
   add_exit("oeste"     ,REAL"real41.c","road");
   set_light(65);
   crea_bichos();
}
