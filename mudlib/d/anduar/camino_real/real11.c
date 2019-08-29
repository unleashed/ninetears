// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Hacia el oeste observas en la "
   "distancia las grandes montanyas de Kheleb-Dum la ciudad fortaleza de los "
   "enanos en las cuales viven millares de los mismos desde tiempos muy "
   "remotos.");
   add_exit("noroeste"   ,REAL"real12.c","road");
   add_exit("southeast"     ,REAL"real10.c","road");
   set_light(65);
   crea_bichos();
}
