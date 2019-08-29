#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^YELLOW%^Palacio de Justicia de Noella%^RESET%^");
     set_long("%^YELLOW%^Palacio de Justicia de Noella%^RESET%^\n\n"+
      "Est�s sobre un suelo de baldosas que dibujan una balanza dirigida al estrado, al igual " +
      "que una multitud de asientos de madera. Sobre la pared del fondo puedes ver un tapiz en " +
      "el que distingues la figura de un hombre a punto de ser decapitado con multitud de " +
      "cabezas a sus pies.\n\n");

    set_light(70);

add_item("asientos","Fabricados de madera y formando dos grandes grupos paralelos, son el " +
        "lugar donde las gentes de la ciudad vienen a presenciar alguno de los juicios.\n");

add_item(({"suelo","baldosas"}), "Las baldosas del suelo que pisas dibujan claramente una gran " +
        "balanza caida hacia un lado.\n");

add_item(({"pared","tapiz"}), "Hay un gran tapiz en la pared del fondo que representa una " +
        "escena muy del agrado del juez. Se trata de la decapitaci�n de un condenado a muerte " +
        "que al parecer, llora irremediablemente al mirar las cabezas de sus predecesores " +
        "reposando a sus pies.\n");

add_exit("fuera", CALLE+"calle11","road");
}
