// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, A lo lejos en la distancia al "
   "suroeste observas la ciudad de Kheleb-Dum, la montanya ciudad de los "
   "enanos, una de las razas mas nobles de este mundo, que antes de levantar "
   "un arma sobre un hermano suyo se quitaria la vida.");
   add_exit("noroeste"   ,REAL"real38.c","road");
   add_exit("southeast"     ,REAL"real36.c","road");
   set_light(65);
   crea_bichos();
}