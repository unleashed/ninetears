#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("norte", MERCADO+"mercado5","road");
add_exit("noreste", MERCADO+"mercado6","road");
add_exit("este", MERCADO+"mercado11","road");
add_exit("sur", MERCADO+"mercado14","road");
}
