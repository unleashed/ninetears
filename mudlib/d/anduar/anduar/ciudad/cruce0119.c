// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Norte y Calle de Oskuro%^RESET%^");
   set_long("Estas en un cruce entre la calles norte y la prolongacion de la "
        "antigua calle este, ahora llamada Calle de Oskuro. Hay un murmullo "
        "constante de la gente que pasea por las calles. Observas que casi "
        "todos sus habitantes son humanos, aunque se puede ver algun que otro "
        " enano o elfo.\n");
   add_exit("oeste"   ,ANDUAR"no0118.c","road");
   add_exit("este"    ,ANDUAR"no0120.c","road");
   add_exit("sur"     ,ANDUAR"ae0219.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}