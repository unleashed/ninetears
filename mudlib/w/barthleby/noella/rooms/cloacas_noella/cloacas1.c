#include "/w/barthleby/path.h"

inherit CLOACAS"std_cloacas.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Cloacas de Noella%^RESET%^");
   long_desc_cloacas();




//add_clone(NPC+"rata_gigante", 1);

add_exit("sur", CLOACAS+"cloacas2","corridor");
}
