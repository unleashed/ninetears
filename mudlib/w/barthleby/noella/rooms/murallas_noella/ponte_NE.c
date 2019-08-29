#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Puente de Traba%^RESET%^");
     set_long("%^YELLOW%^Puente de Traba%^RESET%^\n\n"+
      "El m�s antiguo sin duda de los puentes sobre el Trabasir, lo que se aprecia a " +
      "simple vista si nos fijamos en la erosi�n sufrida por las grandes rocas con " +
      "que est� constru�do. Al ser bastante estrecho, fue dise�ado con tres " +
      "salientes, uno a un lado y dos al otro, intercalados para que los caminantes " +
      "puedan hacerse a un lado si se cruzan con alg�n carro.\n\n");

    set_light(70);

add_item(({"puente", "Puente"}),"La parte exterior de las rocas del puente se " +
        "encuentra cubierta con una capa de verde musgo m�s espesa cuanto m�s " +
        "cerca del nivel del r�o. Siempre suele haber alguna que otra rama de las que " +
        "llegan arrastradas por el r�o en la base de sus pilares. \n");

add_item(({"rio", "r�o", "Trabasir"}),"El Trabasir, un no muy ancho pero si hermoso r�o " +
        "con abundante pesca, en el que algunos j�venes ba�istas se dejan ver " +
        "durante los d�as m�s calientes del a�o. \n");

add_exit("noroeste", MURALLAS_NOELLA+"entra_muralla1","road");
add_exit("este", COUTO+"couto1","road");
set_zone("muralla");

}
