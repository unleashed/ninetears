// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En este punto, la calzada vuelve a "
   "cambiar de rumbo, para rodear una roca de una dureza tal, que ni los "
   "senyores enanos ha logrado perforar, ni los grandes magos mover.");
   add_exit("noroeste"   ,REAL"real17.c","road");
   add_exit("sur"     ,REAL"real15.c","road");
   set_light(65);
   crea_bichos();
}