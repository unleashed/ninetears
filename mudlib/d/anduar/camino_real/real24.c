// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Aqui la calzada se desvia de repente  "
   "hacia el este para encaminarse al puente, tal vez el puente fuese "
   "construido antes que la calzada, ya que observas que el puente, de un solo "
   "ojo parece salir de la roca, como si fuese parte de ella.");
   add_exit("noreste"   ,REAL"real25.c","road");
   add_exit("sur"     ,REAL"real23.c","road");
   set_light(65);
   crea_bichos();
}