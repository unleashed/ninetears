// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Este%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"puerta1325.c","road");
   add_exit("sur"     ,ANDUAR"es1525.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}