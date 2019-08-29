/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^WHITE%^Cruce Calle del General con Calle Eliss%^RESET%^");
   long_desc();


   crea_npcs();

add_exit("este",      BRETHEM + "gen5.c","standard");
add_exit("oeste",     BRETHEM + "gen7.c","standard");
add_exit("norte",     BRETHEM + "eliss1.c","standard");
add_exit("dentro",    BRETHEM + "panaderia1.c","standard");

}
