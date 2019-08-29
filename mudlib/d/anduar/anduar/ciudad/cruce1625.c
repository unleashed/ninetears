// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Este%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"es1525.c","road");
   add_exit("sur"     ,ANDUAR"es1725.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}