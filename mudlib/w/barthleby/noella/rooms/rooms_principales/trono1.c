#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^");
     set_long("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^\n\n"+
      "Este es el recibidor, una gran estancia a la que se accede por unos largos escalones de " +
      "piedra. Sobre sus paredes puedes ver tallado el escudo de la ciudad. Tres escalones m�s, " +
      "tambi�n de piedra, conducen al patio.\n\n");

    set_light(70);

add_item("escalones","Estos son los tres largos escalones que conducen al patio del palacio.\n");

add_item(({"escudo","pared"}),"Puedes ver el escudo de la ciudad de Noella tallado en la pared. " +
        "Consiste en un gran arca sobre el mar, rodeada por una cadena.\n");

//add_clone(NPC+"guardia_noella", 2);

add_exit("fuera", PRINCIPALES+"destino","road");
add_exit("patio", PRINCIPALES+"trono2","road");
}
