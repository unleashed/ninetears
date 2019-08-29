/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   set_exit_color("cyan");
   set_short("%^BOLD%^RED%^Ciudad de Brethem : %^BOLD%^WHITE%^Calle del General%^RESET%^");
   long_desc();
   base_desc();

   crea_npcs();

add_exit("oeste",      BRETHEM + "gen3.c","standard");
add_exit("este",       BRETHEM + "gen1.c","standard");

}
