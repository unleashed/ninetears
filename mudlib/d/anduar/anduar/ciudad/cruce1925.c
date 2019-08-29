// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Este y de Dendara%^RESET%^");
   set_long("Estas en un cruce entre la calles este y la prolongacion de la "
        "antigua calle sur, ahora llamada Calle de Dendara. Hay un murmullo "
        "constante de la gente que pasea por las calles. Observas que casi "
        "todos sus habitantes son humanos, aunque se puede ver algun que otro "
        "enano o elfo.\n");
   add_exit("norte"   ,ANDUAR"es1825.c","road");
   add_exit("oeste"   ,ANDUAR"as1924.c","road");
   add_exit("sur"     ,ANDUAR"es2025.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}