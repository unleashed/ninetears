#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Justo a la salida de la pequenya aldea y ya los arboles se cierran en torno "
    "a ti. Sera mejor que no sufras de claustrofobia, o lo pasaras mal entre "
    "tanto arbol rodeandote, la sensacion es agobiante. Ademas de arboles "
    "no hay mucho mas por aqui. Afortunadamente puedes ver una especie de senda "
    "que atraviesa de norte a sur, ademas, claro, del camino que te lleva de vuelta a "
    "la relativa seguridad de la aldea. "
    "\n\n");
    add_item("aldea","Llamarla aldea es casi exagerado, solo son una pocas casas "
    "mas o menos agrupadas. "
    "\n");
    add_item("senda","Una senda que alguien ha abierto a traves de la densa "
    "jungla. "
    "\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j05.c","path");
    add_exit("sur",HAVMAND+"j07.c","path");
    add_exit("oeste",HAVMAND+"t03.c","path");
    add_exit("sudeste",HAVMAND+"j08.c","path");


    ::init();
}


