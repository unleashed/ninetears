// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Ya al lado del cauce del rio, el "
   "ruido se hace ensordecedor, observas como debajo del puente unas grandes "
   "rocas punteagudas salen del agua, como gigantescas agujas, que "
   "provocarian la muerte de cualquier desgraciado que se cayese sobre las "
   "mismas.");
   add_exit("este"   ,REAL"real27.c","road");
   add_exit("oeste"     ,REAL"real25.c","road");
   set_light(65);
   crea_bichos();
}
