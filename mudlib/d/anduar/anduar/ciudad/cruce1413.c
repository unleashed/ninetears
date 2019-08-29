// Aokromes
#include "../path.h"
inherit ANDUAR+"rica.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos sus "
        "habitantes son humanos, aunque se puede ver algun que otro enano o "
        "elfo.\n");
   add_exit("noroeste",ANDUAR"cruce1312.c","road");
   add_exit("norte"   ,ANDUAR"cruce1313.c","road");
   add_exit("noreste" ,ANDUAR"cruce1314.c","road");
   add_exit("sur"     ,ANDUAR"cc1513.c","road");
   add_exit("west", "/d/clanes/valle_del_sol/rooms/main","door");
   modify_exit("west", ({"function","entrar_clan"}));   
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}

int entrar_clan()
{
  notify_fail("Entrada privada de clan, lo siento.\n");
  if(TP->query_group_name() !="Valle del Sol") return 0;
  return 1;
}
