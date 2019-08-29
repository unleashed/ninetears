// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Oeste%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"oe1501.c","road");
   add_exit("sur"     ,ANDUAR"oe1701.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}