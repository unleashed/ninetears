// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: calle Oeste%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"oe0501.c","road");
   add_exit("sur"     ,ANDUAR"cruce0701.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}