// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_light(60);
    set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   long_desc();
   add_exit("este"    ,ANDUAR"precipicio2417.c","road");
   add_exit("sudoeste",ANDUAR"precipicio2515.c","road");
}
