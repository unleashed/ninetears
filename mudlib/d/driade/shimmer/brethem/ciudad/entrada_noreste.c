/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("red");
   set_short("%^BOLD%^RED%^Puerta Noreste de %^YELLOW%^Brethem%^RESET%^");
   set_long("%^BOLD%^RED%^Puerta Noreste de Brethem%^RESET%^\n\n"
            "Un estrecho callejon que une la Avenida del Este con el Paseo de la Playa, en este callejon pega un fuerte viento "
            "cargado de humedad y transportando arena de la playa que hay al sur, por lo que te cuesta caminar y te tienes que "
            "cubrir la cara para que no te entren arenas en los ojos.\n\n");

     

   add_exit("norte",        BRETHEM + "muralla.c","standard");
   add_exit("sur",          BRETHEM + "muralla.c","standard");
   add_exit("este",         BRETHEM + "nuse.c","standard");
   add_exit("sudoeste",     BRETHEM + "av_harak7.c","standard");
   modify_exit("sudoeste",({"function","do_entrada"}));

   add_clone(BRETHEM + "npcs/guardias_entrada.c", 2);

}

int do_entrada()
{

	write("Pasas bajo el gran arco de la muralla hacia el interior de la ciudad.\n\n");
return 1;
}
