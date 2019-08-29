// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Norte%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"no0123.c","road");
   add_exit("este"    ,ANDUAR"cruce0125.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}