// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Norte%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"no0109.c","road");
   add_exit("este"    ,ANDUAR"no0111.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}