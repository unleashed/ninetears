// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos "
        "sus habitantes son humanos, aunque se puede ver algun que otro enano "
        "o elfo. Hay una tapa metalica en el suelo.\n");
   add_exit("noroeste",ANDUAR"cruce1807.c","road");
   add_exit("oeste"   ,ANDUAR"cruce1907.c","road");
   add_exit("este"    ,ANDUAR"as1909.c","road");
   add_exit("sudoeste",ANDUAR"cruce2007.c","road");
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
   this_player()->move(CLOACAS"c57.c");
   this_player()->look_me();
   return 1;
}
