#include "/w/barthleby/path.h"

inherit CLOACAS"std_cloacas.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Catacumbas de Noella%^RESET%^");
   long_desc_catacumbas();





//add_clone(NPC+"rata_gigante", 1);

add_exit("noroeste", CLOACAS+"catacumbas2","corridor");
add_exit("sudoeste", CLOACAS+"catacumbas4","corridor");
set_zone("catacumbas");

}

