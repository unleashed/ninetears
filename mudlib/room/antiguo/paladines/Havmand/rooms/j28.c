#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "En esta zona se nota algun cambio, posiblemente debido al "
    "cambio de altitud, la jungla es menos densa, el suelo esta mas "
    "despejado, y hay alguna que otra roca que sobresale de entre la "
    "vegetacion del suelo. Aun se puede subir siguiendo la descuidada "
    "senda que aqui gira al sudoeste."
    "\n\n");
    add_item("rocas",
    "Las rocas estan hundidas en el suelo, pero una parte sobresale quedando "
    "a la vista, son rugosas y estan cubiertas parcialmente de musgo. "
    "\n");

}
void init()
{
    add_exit("sudoeste",HAVMAND+"j29.c","path");
    add_exit("noroeste",HAVMAND+"j27.c","path");

    ::init();
}




