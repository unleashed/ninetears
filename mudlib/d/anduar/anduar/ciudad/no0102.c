// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Norte%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"cruce0101.c","road");
   add_exit("este"    ,ANDUAR"no0103.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}