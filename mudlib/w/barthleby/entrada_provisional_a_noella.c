inherit "/std/outside.c";

#include "/w/barthleby/path.h"

void setup()

{
    set_short("%^BOLD%^%^BLUE%^Entrada provisional a%^RED%^ Noella%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Entrada provisional a%^RED%^ Noella%^RESET%^\n\n"+
      "Est�s en la entrada provisional a Noella. Desde aqu� se llega a todos los " +
      "caminos sin enlazar con una room final y todos esos caminos llevan aqu�.\n" +
      "%^BOLD%^%^BLUE%^cne %^RESET%^te llevar� al Camino Nordeste.\n" +
      "%^BOLD%^%^BLUE%^cn %^RESET%^te llevar� al Camino Norte.\n" +
      "%^BOLD%^%^BLUE%^cse %^RESET%^te llevar� al Camino Sudeste.\n" +
      "%^BOLD%^%^BLUE%^cs %^RESET%^te llevar� al Camino Sur.\n\n");


    set_light(70);

add_item("camino","Es un camino lo suficientemente ancho como para un gran carro " +
        "que se va estrechando cada d�a m�s por el lento pero imparable avance de " +
        "la vegetaci�n de sus bordes. \n");

//add_clone(NPC+"epos", 1);
//add_clone(NPC+"crea_bichos", 1);

add_exit("cne", CAMINO_NORDESTE+"camino_nordeste12","road");
add_exit("cn", CAMINO_NORTE+"camino_norte7","road");
add_exit("cse", CAMINO_SUDESTE+"camino_sudeste11","road");
add_exit("cs", CAMINO_SUR+"camino_sur3","road");

add_clone("/w/barthleby/noella/npcs/gargola",random(1));

}
