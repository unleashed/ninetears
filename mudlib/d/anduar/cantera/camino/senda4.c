// Aokromes, Julio de 1999
#include "../../path.h"
inherit CANTERA+"afueras.c";

void setup()
{
   set_short("%^BLUE%^BOLD%^Camino a la cantera%^RESET%^");
   set_long("Estas en un camino dedicado a llevar la roca de la cantera al "
   "Real Camino, este a diferencia del Real Camino no tiene desagues, ni esta "
   "tan cuidado, cosa logica ya que una vez finalizado el mismo no tiene razon "
   "de ser.");

   add_exit("northeast"   ,CANTERA"senda3.c","road");
   add_exit("southwest"   ,CANTERA"senda5.c","road");
   set_light(65);
   crea_bichos();
}
