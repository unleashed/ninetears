#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^RED%^Minas de hierro de Noella. Entrada%^RESET%^");
     set_long("%^RED%^Minas de hierro de Noella. Entrada%^RESET%^\n\n"+
      "Unas puertas de madera ya podridas estan abiertas ante ti, dir�as que no se han cerrado " +
      "en muchos a�os, y estar�as en lo cierto, ya que desde el establecimiento de los " +
      "maestros constructores y forjadores en Noella, los picos, palas y carros han estado " +
      "activos d�a y noche.\n\n");

    set_light(50);

add_item(({"puerta","puertas"}),"Las dos puertas que deber�an cerrar el paso a las minas han " +
        "estado sin uso durante tanto tiempo que han sido descuidadas y se encuentran en un " +
        "lamentable estado.\n");

add_exit("este", CAMINO_SUDESTE+"camino_sudeste6","road");
add_exit("sudoeste", HIERRO+"hierro2","road");
set_zone("mina_hierro");
}

