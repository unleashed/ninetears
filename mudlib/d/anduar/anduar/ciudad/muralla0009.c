// Aokromes
#include "../path.h"
inherit ANDUAR+"afueras.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Muralla%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"muralla0008.c","road");
   add_exit("este"    ,ANDUAR"muralla0010.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}