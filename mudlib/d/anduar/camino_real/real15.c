// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Tras mucho observar ves a lo lejos "
   "al este la ciudad fortificada de Takome, la ciudad de los paladines, "
   "orgullosos guerreros que luchan con su fe en los dioses, que les dan "
   "fuerza al corazon y al alma para seguir en su santa lucha.");
   add_exit("norte"   ,REAL"real16.c","road");
   add_exit("sur"     ,REAL"real14.c","road");
   set_light(65);
   crea_bichos();
}