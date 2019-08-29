#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Bloque A%^RESET%^");
     set_long("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Bloque A%^RESET%^\n\n"+
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

add_exit("sudoeste", PRISION+"bloque_A1","corridor");
add_exit("noreste", PRISION+"bloque_A4","corridor");
add_exit("este", PRISION+"bloque_A3","corridor");
add_exit("sudeste", PRISION+"prision12","corridor");
add_exit("sur", PRISION+"bloque_A2","corridor");
}

/*Falta el mecanismo que abra las puertas tras haberle introducido algo que llevara uno de los guardias*/
