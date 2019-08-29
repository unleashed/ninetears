#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^");
     set_long("%^BOLD%^%^RED%^Palacio de Mu-Bai%^RESET%^\n\n"+
      "Has llegado al patio central. De forma rectangular y con un pasillo cuierto alrededor, " +
      "es la herencia del convento sobre el que fue constru�do este palacio. La parte central " +
      "consiste en un jardincito con una peque�a fuente en medio.\n\n");

    set_light(70);

add_item("fuente", "La peque�a fuente central del patio, no tiene otra funci�n que la de " +
        "saciar la sed de los pajarillos que se acercan al lugar.\n");

add_item(({"jardincito","jard�n","jardin"}),"Es un sencillo jardincito muy bien cuidado, salpicado por " +
        "alguna que otra flor.\n");

add_item("pasillo","Se trata de un pasillo cubierto que corre pegado a la pared y tiene " +
        "cuatro peque�os accesos al jardin central.\n");

//add_clone(NPC+"guardia_noella", 2);

add_exit("norte", PRINCIPALES+"trono3","road");
add_exit("recibidor", PRINCIPALES+"trono1","road");
}
