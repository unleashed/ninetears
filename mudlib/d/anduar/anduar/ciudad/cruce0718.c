// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una zona verde en un cruce entre las antiguas calles "
        "sur y este, oyes el murmullo constante de la gente que pasea por las "
        "calles. Observas que casi todos sus habitantes son humanos, aunque "
        "se puede ver algun que otro enano o elfo.\n");
   add_exit("noreste" ,ANDUAR"cruce0619.c","road");
   add_exit("oeste"   ,ANDUAR"cruce0717.c","road");
   add_exit("este"    ,ANDUAR"cruce0719.c","road");
   add_exit("sudeste" ,ANDUAR"cruce0819.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
void init()
{
   ::init();
   add_action("cloaca", "levanta*r");
   add_action("cloaca", "quita*r");
}

void cloaca(string tapa)
{
   if (!tapa || tapa!="tapa")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }
   write("\nLevantas la tapa sigilosamente y te introduces dentro de las "
   "cloacas, no sin antes tapar de nuevo el agujero para evitar que alguien "
   "caiga dentro.\n");
   say(this_player()->query_cap_name()+" levanta algo sigilosamente y se "
   "mete por un agujero.\n");
   this_player()->move(CLOACAS"c69.c");
   this_player()->look_me();
   return 1;
}
