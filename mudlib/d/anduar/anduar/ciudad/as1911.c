// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Dendara%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"as1910.c","road");
   add_exit("este"    ,ANDUAR"cruce1912.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}