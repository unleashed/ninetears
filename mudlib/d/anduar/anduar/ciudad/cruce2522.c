// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_light(60);
   set_short("%^YELLOW%^Ciudad de Anduar: Precipicio%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"precipicio2521.c","road");
   add_exit("este"    ,ANDUAR"precipicio2523.c","road");
}
