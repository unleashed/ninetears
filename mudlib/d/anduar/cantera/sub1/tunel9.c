// Aokromes tunel 9
#include "../../path.h"
inherit CANTERA3+"cantera.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar%^RESET%^");
   set_long("Estas en la Real cantera de Anduar, la cual fue utilizada para "
   "proporcionar roca al Real camino, este pasadizo, lleno de humedad parece "
   "descender poco a poco a las entranyas de la tierra.\n");
   add_exit("northwest" ,CANTERA3"tunel10","road");
   add_exit("sur"       ,CANTERA3"tunel8","road");
   set_zone("cantera");
crea_bichos();
}


void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
