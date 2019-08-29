/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("yellow");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^RED%^Callejon del Este%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^RED%^Callejon del Este%^RESET%^\n\n"
            "Un estrecho callejon que une la Avenida del Este con el Paseo de la Playa, en este callejon pega un fuerte viento "
            "cargado de humedad y transportando arena de la playa que hay al sur, por lo que te cuesta caminar y te tienes que "
            "cubrir la cara para que no te entren arenas en los ojos.\n\n");

     
   crea_npcs_callejon();

add_exit("norte",        BRETHEM + "av_este9.c","standard");
add_exit("sur",          BRETHEM + "callejon11.c","standard");

}
