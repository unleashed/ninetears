// Aokromes, Julio de 1999
#include "../../path.h"
inherit CANTERA+"afueras.c";

void setup()
{
   set_short("%^BLUE%^BOLD%^Camino a la cantera%^RESET%^");
   set_long("Estas en un camino dedicado a llevar la roca de la cantera al "
   "Real Camino, este a diferencia del Real Camino no tiene desagues, ni esta "
   "tan cuidado, cosa logica ya que una vez finalizado el mismo no tiene razon "
   "de ser, por aqui los maleantes campan a sus anchas, ya que no hay "
   "guardianes que lo cuiden.");

   add_exit("northeast"   ,CANTERA"senda9.c","road");
   add_exit("oeste"   ,CANTERA"senda11.c","road");
   set_light(65);
   crea_bichos();
}
