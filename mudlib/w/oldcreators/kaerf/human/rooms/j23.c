#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Los arboles permanecen muy juntos, hay troncos que casi se tocan. Aparte "
    "de al norte y al sur no hay otras rutas posibles en las que avanzar. "
    "Arriba en las alturas ves un nido de algun ave, y en el suelo "
    "esta la rama caida de un arbol. "
    "\n\n");
    add_item("nido","Es el nido de algun tipo de ave. Parece hecha de "
    "ramitas y musgo. Esta lo bastante alto para evitar a los predadores. "
    "\n");
    add_item("rama","Es una rama que ha caido de algun arbol, esta "
    "parcialmente podre, con cuidado puedes pasar por encima de ella "
    "sin lastimarte y seguir tu camino."
    "\n");

}
void init()
{
    add_exit("sur",HAVMAND+"j16.c","path");
    add_exit("noroeste",HAVMAND+"j24.c","path");


    ::init();
}


