// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Hacia el este observas los lindes "
   "de Orgoth el gran bosque que cubre miles de hectareas que dicen que "
   "nadie lo ha explorado por completo y que mucha gente se ha perdido y no "
   "ha vuelto a casa.");
   add_exit("norte"   ,REAL"real13.c","road");
   add_exit("southeast"     ,REAL"real11.c","road");
   set_light(65);
   crea_bichos();
}
