/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit CLOACASBRE+"cloacasroom.c";

void setup()
{
   base_desc();
   set_exit_color("black");
   set_short("%^BOLD%^BLUE%^Cloacas de Brethem:%^BLACK%^ Tuneles Superiores%^RESET%^");
   long_desc();

   crea_npcs();

   add_exit("noroeste",    CLOACASBRE + "clo9", "corridor");
   add_exit("este",        CLOACASBRE + "clo7",  "corridor");


}
