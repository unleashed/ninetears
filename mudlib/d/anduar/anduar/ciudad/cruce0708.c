// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos sus "
        "habitantes son humanos, aunque se puede ver algun que otro enano o "
        "elfo.\n");
   add_exit("noroeste",ANDUAR"cruce0607.c","road");
   add_exit("oeste"   ,ANDUAR"cruce0707.c","road");
   add_exit("este"    ,ANDUAR"an0709.c","road");
   add_exit("sudoeste",ANDUAR"cruce0807.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}