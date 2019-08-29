// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Sur%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"su2509.c","road");
   add_exit("este"    ,ANDUAR"su2511.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}