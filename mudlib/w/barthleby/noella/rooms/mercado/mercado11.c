#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("oeste", MERCADO+"mercado10","road");
add_exit("noroeste", MERCADO+"mercado5","road");
add_exit("norte", MERCADO+"mercado6","road");
add_exit("noreste", MERCADO+"mercado7","road");
add_exit("este", MERCADO+"mercado12","road");
add_exit("sudeste", MERCADO+"mercado16","road");
add_exit("sur", MERCADO+"mercado15","road");
add_exit("sudoeste", MERCADO+"mercado14","road");
}
