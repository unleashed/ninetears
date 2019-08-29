// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Paris%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"ao1607.c","road");
   add_exit("sur"     ,ANDUAR"cruce1807.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
