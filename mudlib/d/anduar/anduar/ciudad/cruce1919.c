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
   add_exit("norte"   ,ANDUAR"cruce1819.c","road");
   add_exit("oeste"   ,ANDUAR"cruce1918.c","road");
   add_exit("este"    ,ANDUAR"cruce1920.c","road");
   add_exit("sur"     ,ANDUAR"cruce2019.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}