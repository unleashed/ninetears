#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("norte", MERCADO+"mercado1","road");
add_exit("noreste", MURALLAS_NOELLA+"muralla42","road");
add_exit("este", MERCADO+"mercado4","road");
add_exit("sudeste", MERCADO+"mercado8","road");
add_exit("sur", MERCADO+"mercado7","road");
add_exit("sudoeste", MERCADO+"mercado6","road");
}
