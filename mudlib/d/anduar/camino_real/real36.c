// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En la distancia, mas alla del "
   "bosque de Orgoth observas como sobresalen algunas torres de alguna urbe "
   "por su posicion lo mas probable es que sea la ciudad fortificada de "
   "Takome, hogar de la santa orden de los paladines.");
   add_exit("noroeste"   ,REAL"real37.c","road");
   add_exit("sur"     ,REAL"real35.c","road");
   set_light(65);
   crea_bichos();
}