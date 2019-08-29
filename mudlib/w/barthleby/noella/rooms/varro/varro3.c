#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^BOLD%^%^ORANGE%^Minas de Varro. Entrada%^RESET%^");
     set_long("%^BOLD%^%^ORANGE%^Minas de Varro. Entrada%^RESET%^\n\n"+
      "Te encuentras ante un paso estrecho destinado a la vigilancia y regulaci�n de la entrada " +
      "a las antiguas minas de los humanos. Pero ya no son estos los que lo controlan. Est�s " +
      "hundido casi hasta las rodillas en el p�lido y gris suelo arcilloso.\n\n");

    set_light(30);

add_exit("oeste", VARRO+"varro13","road");
add_exit("norte", VARRO+"varro4","road");
add_exit("este", VARRO+"varro2","road");
}

