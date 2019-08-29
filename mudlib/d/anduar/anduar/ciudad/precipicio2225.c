// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"es2125.c","road");
   add_exit("sudeste" ,ANDUAR"precipicio2326.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}