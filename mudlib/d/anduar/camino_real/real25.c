// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Aqui observas que tus temores de "
   "caerte eran infundados, ya que una alta verja rodea los limites del "
   "puente lo cual evita cualquier accidente en el mismo.");
   add_exit("este"   ,REAL"real26.c","road");
   add_exit("southwest"     ,REAL"real24.c","road");
   set_light(65);
   crea_bichos();
}
