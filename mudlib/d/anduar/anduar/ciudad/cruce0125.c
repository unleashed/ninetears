// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Norte y Este%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"no0124.c","road");
   add_exit("sur"     ,ANDUAR"es0225.c","road");
add_exit("arriba"   ,ANDUAR"torre_ne.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
