// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Hacia el suroeste puedes observar "
   "unas grandes canteras de las cuales parece provenir las rocas de la "
   "calzada y al norte ves el cauce del rio Urzabalgai, aqui mucho mas grande "
   "que en los desfiladeros del bosque de Orgoth, hacia los cuales se dirige.");
   add_exit("norte"   ,REAL"real21.c","road");
   add_exit("southeast"     ,REAL"real19.c","road");
   add_exit("southwest"   ,CANTERA"senda1.c","road");
   set_light(65);
   crea_bichos();
}
