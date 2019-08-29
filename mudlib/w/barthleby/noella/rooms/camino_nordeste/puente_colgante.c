#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^ORANGE%^Puente colgante%^RESET%^");
     set_long("%^ORANGE%^Puente colgante%^RESET%^\n\n"+
      "Caminas por un tremendamente inestable puente sobre la parte norte del Trabasir entre " +
      "tabla y tabla se distinge perfectamente el curso de las aguas por la parte, sin lugar a " +
      "dudas, m�s r�pida del r�o. Desde aqu� puedes distinguir un extranyo brillo al otro lado " +
      "del puente. Deber�as estar alerta si no quieres caerte.\n\n");

    set_light(40);

add_item(({"puente", "Puente"}),"El puente esta constru�do con lianas y tablas, las cuales " +
            "parecen extraordinariamente flexibles pero no parecen ser muy seguras, no " +
            "estar�a de m�s ir con cuidado. \n");

add_item(({"rio", "r�o", "Trabasir"}),"El Trabasir, un no muy ancho pero si hermoso r�o " +
        "con abundante pesca, en el que algunos j�venes ba�istas se dejan ver " +
        "durante los d�as m�s calientes del a�o. \n");

add_exit("noroeste", BOSQUE+"bosque_noella9","road");
add_exit("sudeste", CAMINO_NORDESTE+"camino_nordeste11","road");
}
