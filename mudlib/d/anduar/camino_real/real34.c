// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Desde aqui observas como a lo lejos "
   "al suroeste una curiosa construccion se extiende a lo largo del horizonte, "
   "sin embargo no aparece en ningun mapa ni plano de los que hayas visto "
"jamas.");
   add_exit("norte"   ,REAL"real35.c","road");
   add_exit("southeast"     ,REAL"real33.c","road");
   set_light(65);
   crea_bichos();
}
