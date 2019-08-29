#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Puente de Barthleby%^RESET%^");
     set_long("%^YELLOW%^Puente de Barthleby%^RESET%^\n\n"+
      "Resulta un extra�o puente debido a su bifurcaci�n central, que no perece "+
      "tener otro objeto que el meramente est�tico. Est� bastante por encima del " +
      "nivel del Trabasir, incluso en sus crecidas. Algunos llegan incluso a tener " +
      "v�rtigo cuando se aproximan demasiado a los bordes.\n\n");

    set_light(70);

add_item(({"puente", "Puente"}),"Se trata de un solido puente de piedra sustentado " +
        "por cuatro enormes pilares al fondo, que forman un rombo imaginario en el " +
        "centro del r�o. \n");

add_item(({"rio", "r�o", "Trabasir"}),"El Trabasir, un no muy ancho pero si hermoso r�o " +
        "con abundante pesca, en el que algunos j�venes ba�istas se dejan ver " +
        "durante los d�as m�s calientes del a�o. \n");

add_exit("noroeste", MURALLAS_NOELLA+"entra_muralla4","road");
add_exit("este", MURALLAS_NOELLA+"ponte_E2","road");
add_exit("sur", MURALLAS_NOELLA+"ponte_E3","road");
set_zone("muralla");

}
