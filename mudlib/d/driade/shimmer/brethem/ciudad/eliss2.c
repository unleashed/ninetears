/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Calle Eliss%^RESET%^");
   long_desc();

   crea_npcs();

add_exit("norte",     BRETHEM + "eliss3.c","standard");
add_exit("sur",       BRETHEM + "eliss1.c","standard");

}
