// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: cruce entre Calle Oeste y Norte%^RESET%^");
   long_desc();
   add_exit("este"    ,ANDUAR"no0102.c","road");
   add_exit("sur"     ,ANDUAR"oe0201.c","road");
add_exit("arriba"    ,ANDUAR"torre_no.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
