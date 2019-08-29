/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^WHITE%^Calle del General%^RESET%^");
   long_desc();


   crea_npcs();

add_exit("oeste",      BRETHEM + "gen17.c","standard");
add_exit("este",       BRETHEM + "gen15.c","standard");
add_exit("noroeste",   BRETHEM + "descub1.c","standard");
add_exit("norte",      BRETHEM + "plaza_catedral.c","standard");
add_exit("sur",        BRETHEM + "plaza_eleisson1.c","standard");


}
