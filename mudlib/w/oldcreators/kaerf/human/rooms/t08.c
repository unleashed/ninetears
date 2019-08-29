#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un camino sucio y descuidado que corre paralelo a un grotesco poblado "
    "construido al oeste, bajo la muralla de un castillo. Al este esta la inevitable "
    "y odiosa jungla... algun dia deberas encontrar la manera de salir de esta isla. "
    "El camino del oeste conduce a una de las pocas viviendas del poblado, "
    "observas que esta vivienda esta en muy mal estado. "
    "\n\n");    

    add_item("vivienda","Es una miserable casita que esta casi en ruinas, muchas "
    "tejas faltan del techo y en sus paredes hay boquetes en varias zonas, casi se "
    "puede ver el interior a traves de ellos. \n");

}
void init()
{
    add_exit("norte",HAVMAND+"t07.c","path");
    add_exit("sur",HAVMAND+"t09.c","path");
    add_exit("oeste",HAVMAND+"v06.c","path");
    add_exit("este",HAVMAND+"j14.c","path");

    ::init();
}

