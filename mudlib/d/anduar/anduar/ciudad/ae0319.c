// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Oskuro%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"ae0219.c","road");
   add_exit("sur"     ,ANDUAR"ae0419.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}