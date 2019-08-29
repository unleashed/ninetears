/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^BLACK%^Avenida del Harak-Din%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^BLACK%^Avenida del Harak-Din%^RESET%^\n\n"
            "Una amplia calzada ascendente se abre ente ti, parte de la Estatua del Leon hacia la gran muralla y la salida "
            "de Bretehm, la calle recibe el nombre del monte Harak situado al noreste de la ciudad y al que se llega por el "
            "camino que continua a esta avenida cuando la misma deja atras la muralla.\n\n");

     
   crea_npcs();

add_exit("sudoeste",     BRETHEM + "av_harak3.c","standard");
add_exit("noreste",      BRETHEM + "av_harak5.c","standard");



}
