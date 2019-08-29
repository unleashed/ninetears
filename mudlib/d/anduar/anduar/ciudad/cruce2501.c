// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Sur y Oeste%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"oe2401.c","road");
   add_exit("este"    ,ANDUAR"su2502.c","road");
add_exit("arriba"   ,ANDUAR"torre_so.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
