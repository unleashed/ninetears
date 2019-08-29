// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Sur%^RESET%^");
  long_desc();
   add_exit("oeste"   ,ANDUAR"su2511.c","road");
   add_exit("este"    ,ANDUAR"puerta2513.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
