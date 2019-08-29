// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Paris%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"cruce1407.c","road");
   add_exit("sur"     ,ANDUAR"ao1607.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}