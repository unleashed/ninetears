// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Este%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"cruce1925.c","road");
   add_exit("sur"     ,ANDUAR"es2125.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}