#include "/w/barthleby/path.h"

inherit CLOACAS"std_cloacas.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Catacumbas de Noella%^RESET%^");
   long_desc_catacumbas();





//add_clone(NPC+"rata_gigante", 3);

add_exit("noreste", CLOACAS+"catacumbas4","corridor");
add_exit("hueco", CLOACAS+"cloacas15","corridor");
set_zone("catacumbas");

}

