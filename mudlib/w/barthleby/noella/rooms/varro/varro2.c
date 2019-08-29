#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^BOLD%^%^ORANGE%^Camino hacia las minas de Varro%^RESET%^");
     set_long("%^BOLD%^%^ORANGE%^Camino hacia las minas de Varro%^RESET%^\n\n"+
      "Est�s cerca de los dominios de Varro. El camino continua en linea recta y descendente en " +
      "direcci�n a unas antiguas minas. Tus pies se hunden cada vez m�s en el suelo arcilloso y " +
      "gris p�lido cuanto m�s te acercas a la entrada.\n\n");

    set_light(30);

add_exit("oeste", VARRO+"varro3","road");
add_exit("este", VARRO+"varro1","road");
}


