// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Oeste y de Takome%^RESET%^");
   set_long("Estas en un cruce entre la calles oeste y la prolongacion de la "
        "antigua calle norte, ahora llamada Calle de Takome. Hay un murmullo "
        "constante de la gente que pasea por las calles. Observas que casi "
        "todos sus habitantes son humanos, aunque se puede ver algun que otro "
        "enano o elfo.\n");
   add_exit("norte"   ,ANDUAR"oe0601.c","road");
   add_exit("este"    ,ANDUAR"an0702.c","road");
   add_exit("sur"     ,ANDUAR"oe0801.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}