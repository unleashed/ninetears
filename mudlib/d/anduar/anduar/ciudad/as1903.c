// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Dendara%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"as1902.c","road");
   add_exit("este"    ,ANDUAR"as1904.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}