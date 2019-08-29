#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("noreste", MERCADO+"mercado2","road");
add_exit("sudeste", MERCADO+"mercado11","road");
add_exit("sur", MERCADO+"mercado10","road");
add_exit("sudoeste", MERCADO+"mercado9","road");
}
