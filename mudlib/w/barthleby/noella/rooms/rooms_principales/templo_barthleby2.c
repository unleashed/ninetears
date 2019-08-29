#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^");
     set_long("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^\n\n"+
      "La forma de este edificio imita por completo a una pagoda. Consta de tres pisos " +
      "comunicados por una escalera central en espiral. Este piso, al igual que los otro dos, " +
      "carece de decoracion alguna, exceptuando un pecho de coraza en la pared norte.\n\n");

    set_light(70);

add_item("coraza","Es la parte pectoral de una coraza, con una cadena tallada sobre el borde del " +
        "mismo sobre fondo plateado, y un garabado central de un arca sobre fondo verde " +
        "met�lico.\n");

add_item("escalera","La escalera tiene forma de espiral ascendente hacia la derecha y comunica " +
        "los tres pisos.\n"); 

add_exit("arriba", PRINCIPALES+"templo_barthleby3","corridor");
add_exit("abajo", PRINCIPALES+"templo_barthleby1","corridor");
}
