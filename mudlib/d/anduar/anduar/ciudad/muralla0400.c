// Aokromes
#include "../path.h"
inherit ANDUAR+"afueras.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Muralla%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"muralla0300.c","road");
   add_exit("sur"     ,ANDUAR"muralla0500.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}