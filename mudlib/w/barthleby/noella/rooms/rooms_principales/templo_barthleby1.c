#include "/w/barthleby/path.h"

inherit "/std/room.c";

void setup()

{
    set_short("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^");
     set_long("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^\n\n"+
      "La forma de este edificio imita por completo a una pagoda. Consta de tres pisos " +
      "comunicados por una escalera central en espiral. Este piso, al igual que los otro dos, " +
      "carece de decoración alguna, exceptuando el escudo de la pared oeste.\n\n");

    set_light(70);

add_item("escudo","Se trata de un escudo grande, con una cadena tallada sobre el borde del " +
        "mismo sobre fondo plateado, y un garabado central de un arca sobre fondo verde " +
        "metálico.\n");

add_item("escalera","La escalera tiene forma de espiral ascendente hacia la derecha y comunica " +
        "los tres pisos.\n");

add_exit("arriba", PRINCIPALES+"templo_barthleby2","corridor");
add_exit("fuera", CALLE+"calle10","road");
}
