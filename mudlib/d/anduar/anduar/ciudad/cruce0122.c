// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle Norte%^RESET%^");
   set_light(80);
   long_desc();
   add_exit("oeste"   ,ANDUAR"no0121.c","road");
   add_exit("este"    ,ANDUAR"no0123.c","road");
   set_zone("Anduar");
   crea_bichos();
}