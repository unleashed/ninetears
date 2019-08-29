// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   long_desc();
   add_exit("noroeste",ANDUAR"precipicio2225.c","road");
   add_exit("sudoeste",ANDUAR"precipicio2425.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
