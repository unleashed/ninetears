// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la calzada que parecia seguir "
   "hacie el norte se desvia de repente hacia el noreste, ya que en esta zona "
   "el desnivel se hace demasiado pronunciado como para poder construir "
   "firmemente y el constructor decidio pegar un rodeo.\n");
   add_exit("noreste"   ,REAL+"real6.c","road");
   add_exit("sur"       ,REAL+"real4.c","road");
   set_light(65);
   crea_bichos();
}