// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   set_long("Estas en un cruce entre la calle que bordea el precipicio y la "
   "prolongacion de la antigua calle este, ahora llamada Calle de Oskuro. Hay "
   "un murmullo constante de la gente que pasea por las calles. Observas que "
   "casi todos sus habitantes son humanos, aunque se puede ver algun que otro "
   "enano o elfo.\n");
   add_exit("norte"   ,ANDUAR"ae2319.c","road");
   add_exit("oeste"   ,ANDUAR"precipicio2418.c","road");
   add_exit("este"    ,ANDUAR"precipicio2420.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}