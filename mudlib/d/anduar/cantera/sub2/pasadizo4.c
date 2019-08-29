// Aokromes
#include "../../path.h"
inherit "/d/anduar/cantera/sub2/cofradia.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar: Cofradia de ladrones"
   "%^RESET%^");
   set_long("Estas en unos pasillos reforzados por unas placas de madera en "
   "las cuales aparece tallada una mano abierta, del techo cuelgan unas "
   "sencillas lamparas de aceite, las cuales dan la escasa iluminacion del "
   "lugar, por lo que ves las estructuras dedicadas a extraer la roca han "
   "sido totalmente retiradas.\n");
   add_exit("norte"    ,COFRADIA"pasadizo5.c","road");
  add_exit("sur"      ,COFRADIA"pasadizo19.c","road");
   add_exit("oeste"    ,COFRADIA"pasadizo3.c","road");
   set_zone("cofradia");
   crea_bichos();
}


void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
