// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Sur y Calle de Paris%^RESET%^");
   set_long("Estas en un cruce entre la calles sur y la prolongacion de la "
   "antigua calle oeste, ahora llamada Calle de Paris. Hay un murmullo "
   "constante de la gente que pasea por las calles. Observas que casi todos "
   "sus habitantes son humanos, aunque se puede ver algun que otro enano o "
   "elfo.\n");
   add_exit("norte"   ,ANDUAR"ao2407.c","road");
   add_exit("oeste"   ,ANDUAR"su2506.c","road");
   add_exit("este"    ,ANDUAR"su2508.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}