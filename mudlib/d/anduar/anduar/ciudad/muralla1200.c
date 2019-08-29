// Aokromes
#include "../path.h"
inherit ANDUAR+"afueras.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Muralla%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"muralla1100.c","road");
   add_exit("este"    ,ANDUAR"muralla1201.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}