// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Takome%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"an0723.c","road");
   add_exit("este"    ,ANDUAR"cruce0725.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}