// Aokromes
#include "../path.h"
inherit ANDUAR+"rica.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Osucaru%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"cc1513.c","road");
   add_exit("sur"     ,ANDUAR"cruce1713.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
