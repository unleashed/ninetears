// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Oskuro%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"cruce0119.c","road");
   add_exit("sur"     ,ANDUAR"ae0319.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}