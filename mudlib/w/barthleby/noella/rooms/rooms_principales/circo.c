#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Circo de Noella%^RESET%^");
     set_long("%^BOLD%^%^RED%^Circo de Noella%^RESET%^\n\n"+
      "Un gran terreno abierto y cubierto de arena, rodeado por un muro ovalado de piedra que " +
      "forma escalones un metro cada uno, sobre los que se sientan las gentes de Noella para " +
      "disfrutar con las exibiciones de los m�s poderosos guerreros, bien sea entre ellos " +
      "mismos, o contra feroces y hambrientos animales salvajes.\n\n");

    set_light(70);

add_item("muro","�ste es el muro que rodea la arena del circo. Se trata de una estructura " +
        "enorme cuya parte interna escalonada, es utilizada en forma de gradas para el " +
        "p�blico.\n");

add_item("arena","La arena que tienes bajo tus pies aun conserva restos de sangre de una " +
        "reciente exibici�n.\n");

add_exit("noreste", MURALLAS_NOELLA+"muralla11","road");
}
