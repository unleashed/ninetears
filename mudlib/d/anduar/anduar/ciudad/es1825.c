// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Este%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"es1725.c","road");
   add_exit("sur"     ,ANDUAR"cruce1925.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}