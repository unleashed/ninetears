// Made by Thalos  01/04/02

inherit "/std/underground";
#include "../../path.h"

void setup() {
   
   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^CYAN%^: Escaleras de la ascension%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^CYAN%^: Escaleras de la ascension%^RESET%^.\n\n""Estas en las escaleras de la ascension, estas  bellas escalinatas de marmol llevan a la parte alta de la ciudad donde se encuentran los nobles, ricos y el rey, asi como las mas bellas tiendas y jardines que se pueden observar en todo Keroon, estas escaleras se encuentran vigiladas por las mejores fuerzas de elite de la guardia duergar, solamente superadas por aquellas que defienden al rey.""\n\n");
   
add_exit("oeste",KEROONPOBRE+"keroon_217.c","standard");
add_exit("escaleras",JARDINES+"keroon_219.c","standard");

}
