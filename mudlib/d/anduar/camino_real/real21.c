// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, en esta zona observas que la gente "
   "parece parar mucho a descansar bien antes de llegar a Comellas o de pasar "
   "el puente ya que el amplia explanada dejada por las obras parece ser "
   "ideal para albergar a muchas personas.");
   add_exit("noreste"   ,REAL"real22.c","road");
   add_exit("sur"     ,REAL"real20.c","road");
   set_light(65);
   crea_bichos();
}
