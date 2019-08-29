/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^GREEN%^Plaza Eleisson%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^GREEN%^Plaza Eleisson%^RESET%^\n\n"
            "Una pequenya plaza se abre ante ti, cuenta con unos pocos bancos de madera y en el centro "
            "una fuentecilla seca adorna el jardin sobre el que se encuentra. Las casas alrededor de la "
            "plaza son bajas y viejas, algunas de ellas posiblemente deshabitadas, es una zona oscura y "
            "bastante humeda dada la proximidad al mar y el descuido que presenta.\n\n");


   crea_npcs_callejon();

add_exit("norte",      BRETHEM + "plaza_eleisson2.c","standard");
add_exit("oeste",      BRETHEM + "callejon003.c","standard");
add_exit("noreste",    BRETHEM + "plaza_eleisson3.c","standard");
add_exit("sur",        BRETHEM + "mar16.c","standard");

}
