#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "A partir de aqui comienza la jungla, en principio no parece complicado "
    "moverse por ella. Hacia el oeste hay un camino en mal estado, tal vez "
    "lleva tiempo en desuso, y al este ves un puente colgante que pasa por "
    "encima de una profunda grieta. "
    "\n\n");
    add_item( ({"puente","colgante"}),"Es un puente hecho con lianas cortadas "
    "de la jungla, parece muy inestable. Atraviesa una profunda grieta que es "
    "demasiado ancha para poder saltarla. "
    "\n");
    add_item("grieta","La grieta es muy ancha y profunda. De hecho no puedes "
    "ver el fondo por mas que miras abajo. Es demasiado ancha para intentar "
    "cruzrla de un salto."
    "\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"t05.c","path");
    add_exit("este",HAVMAND+"j10.c","path");
    add_exit("norte",HAVMAND+"j07.c","path");
    add_exit("sur",HAVMAND+"j11.c","path");

    ::init();
}


