// Aokromes
#include "../../path.h"
inherit CANTERA3+"cantera.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar%^RESET%^");
   set_long("Estas en la Real cantera de Anduar, la cual fue utilizada para "
   "proporcionar roca al Real camino, por todos lados observas restos de "
   "las estructuras dedicadas a extraer la roca.\n");
   add_exit("arriba"     ,CANTERA3"tunel1","road");
   add_exit("abajo"    ,CANTERA3"tunel3","road");
   set_zone("cantera");
crea_bichos();
}


void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
