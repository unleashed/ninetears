/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Calle del Descubridor%^RESET%^");
   long_desc();  

    add_clone(BRETHEM+"npcs/guardia.c",2);
    add_clone(BRETHEM+"npcs/gato.c",random(1));
    add_clone(BRETHEM+"npcs/pajaro.c",random(1));

add_exit("noroeste",    BRETHEM + "descub8.c","standard");
add_exit("sur",         BRETHEM + "descub6.c","standard");
add_exit("dentro",      BRETHEM + "cemen1.c","standard");

}
