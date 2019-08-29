#include "/w/barthleby/path.h"

inherit "/std/room.c";

void setup()

{
    set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Bloque B%^RESET%^");
     set_long("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Bloque B%^RESET%^\n\n"+
      "Este es el bloque del sur de la prisi�n, a tu alrededor se encuentran cuatro celdas con " +
      "sus respectivas puertas corredizas de hierro de dos cuartas de grosor, ser�a una locura " +
      "tratar de abrirlas o cerrarlas con tus manos, calculas que har�a falta la fuerza de 100 " +
      "o tal vez m�s hombres para tan solo conseguir que vibrasen. El sistema de apertura no " +
      "debe estar lejos de aqu�.\n\n");

    set_light(50);

add_item(({"puertas","puerta","celda","celdas"}),"Las puertas de las celdas se encuentran " +
        "cerradas, cosa que hace imposible ver el interior de estas. Tan solo ves el hierro " +
        "negro de las puertas con una peque�a ranura por la que alimentan a los presos.\n");

//add_clone(NPC+"guardia_gorband", 4);

add_exit("oeste", PRISION+"bloque_B2","corridor");
add_exit("noroeste", PRISION+"prision5","corridor");
add_exit("norte", PRISION+"bloque_B3","corridor");
add_exit("noreste", PRISION+"bloque_B4","corridor");
add_exit("sudoeste", PRISION+"bloque_B1","corridor");
}

/*Falta el mecanismo que abra las puertas tras haberle introducido algo que llevara uno de los guardias*/
