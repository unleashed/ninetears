#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("noroeste", MERCADO+"mercado7","road");
add_exit("norte", MERCADO+"mercado8","road");
add_exit("sur", MERCADO+"mercado17","road");
add_exit("sudoeste", MERCADO+"mercado16","road");
}
