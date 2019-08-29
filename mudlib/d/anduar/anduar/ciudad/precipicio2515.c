// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   long_desc();
   add_exit("noreste" ,ANDUAR"cruce2416.c","road");
   add_exit("oeste"   ,ANDUAR"precipicio2514.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}