// Aokromes, Julio de 1999
#include "../../path.h"
inherit CANTERA2+"cantera.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar%^RESET%^");
   set_long("Estas en la Real cantera de Anduar, la cual fue utilizada para "
   "proporcionar roca al Real camino, por todos lados observas restos de "
   "las estructuras dedicadas a extraer la roca.");

   add_exit("este"           ,CANTERA2"n2-5.c","road");
   add_exit("southwest"      ,CANTERA2"n1-7.c","road");
   set_light(65);
   crea_bichos();
}
