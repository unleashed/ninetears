#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("oeste", MERCADO+"mercado14","road");
add_exit("norte", MERCADO+"mercado11","road");
add_exit("noreste", MERCADO+"mercado12","road");
add_exit("este", MERCADO+"mercado16","road");
}
