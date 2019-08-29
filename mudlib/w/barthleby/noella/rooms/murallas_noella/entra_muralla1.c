#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^YELLOW%^Murallas de Noella. Puerta Nordeste%^RESET%^");
     set_long("%^YELLOW%^Murallas de Noella. Puerta Nordeste%^RESET%^\n\n"+
      "Junto con la puerta Norte, es la entrada m�s antigua de las murallas " +
      "de la ciudad. En las garndes y numerosas brechas y fisuras en la " +
      "parte de muralla que rodea esta entrada permanece el recuerdo de " +
      "antiguas guerras encarnizadas por el control de la ciudad que " +
      "vigilaba el que era, antiguamente, �nico puente sobre el r�o " +
      "Trabasir. Asimismo, los extremadamente desgastados adoquines del " +
      "piso de esta entrada son testigos mudos del incontable n�mero de " +
      "gente que ha atravesado las puertas de esta ciudad.\n\n");

    set_light(70);

//add_clone(NPC+"guardia_noella", 3);

add_exit("sudeste", MURALLAS_NOELLA+"ponte_NE","road");
add_exit("sudoeste", MURALLAS_NOELLA+"muralla44","road");
add_exit("noroeste", MURALLAS_NOELLA+"muralla1","road");
add_exit("norte", CAMINO_NORDESTE+"camino_nordeste1","road");
set_zone("muralla");

}



