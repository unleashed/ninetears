// Aokromes, Julio de 1999
#include "../../path.h"
inherit CANTERA2+"cantera.c";

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar%^RESET%^");
   set_long("Estas en la Real cantera de Anduar, la cual fue utilizada para "
   "proporcionar roca al Real camino, por todos lados observas restos de "
   "las estructuras dedicadas a extraer la roca. Esta veta parece que fue "
   "utilizada para extraer la piedra que forma los sumideros.");

   add_exit("este"        ,CANTERA2"n1-4.c","road");
   add_exit("oeste"       ,CANTERA2"n1-6.c","road");
   add_exit("norte"       ,CANTERA2"n2-5.c","road");
   add_exit("sur"         ,CANTERA2"n0-5.c","road");
   set_light(65);
   crea_bichos();
}
