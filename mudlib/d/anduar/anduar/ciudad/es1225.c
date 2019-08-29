// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Este%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"es1125.c","road");
   add_exit("sur"     ,ANDUAR"puerta1325.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}