#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("oeste", MERCADO+"mercado7","road");
add_exit("noroeste", MERCADO+"mercado3","road");
add_exit("norte", MERCADO+"mercado4","road");
add_exit("sur", MERCADO+"mercado13","road");
add_exit("sudoeste", MERCADO+"mercado12","road");
}
