#include "/w/barthleby/path.h"

inherit CLOACAS"std_cloacas.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Cloacas de Noella%^RESET%^");
   long_desc_cloacas();




add_exit("noreste", CLOACAS+"cloacas16","corridor");
add_exit("sudoeste", CLOACAS+"cloacas14","corridor");
}


/*falta la entrada a las catacumbas y lo que permite la entrada tambien*/
