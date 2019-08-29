// Aokromes
#include "../path.h"
inherit ANDUAR+"afueras.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Muralla%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"muralla0011.c","road");
   add_exit("sur"     ,ANDUAR"muralla0112.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}