// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   long_desc();
   add_exit("oeste"   ,ANDUAR"precipicio2417.c","road");
   add_exit("este"    ,ANDUAR"cruce2419.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}