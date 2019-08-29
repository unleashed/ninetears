#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Puente de mercanc�as%^RESET%^");
     set_long("%^YELLOW%^Puente de mercanc�as%^RESET%^\n\n"+
      "La anchura de este puente es considerable, pueden cruzarse perfectamente dos " +
      "grandes carros dejando incluso espacio suficiente para los caminantes. Con " +
      "frecuencia pueden verse pescadores sentados sobre los anchos petriles de " +
      "ambos lados del puente.\n\n");

    set_light(70);

add_item(({"puente", "Puente"}),"Como cualquier puente sobre el que suelen " +
        "transitar animales de tiro y otros tipos de ganado, esta salpicado por " +
        "los excrementos de estos, Resulta bastante dificil cruzarlo sin pisar " +
        "alguno. Cosa que seg�n dicen da suerte. Sus petriles son un lugar ideal " +
        "para sentarse y contemplar la parte, sin duda, mas hermosa del Trabasir.\n");

add_item(({"rio", "r�o", "Trabasir"}),"El Trabasir, un no muy ancho pero si hermoso r�o " +
        "con abundante pesca, en el que algunos j�venes ba�istas se dejan ver " +
        "durante los d�as m�s calientes del a�o. \n");

add_item(({"petril", "petriles"}),"Una especie de borde de grandes piedras a lo largo del " +
        "puente que sirve para evitar caidas y que tambien es un buen lugar para sentarse.\n");

add_exit("norte", MURALLAS_NOELLA+"entra_muralla3","road");
add_exit("sur", MURALLAS_NOELLA+"ponte_S2","road");
set_zone("muralla");

}
