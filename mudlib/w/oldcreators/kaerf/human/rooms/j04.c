#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Te subes encima del tronco de un arbol caido para intentar tener una mejor "
    "vision, pero aun asi lo unico que ves son arboles y mas arboles. La vegetacion "
    "es tan densa al este que forma una barrera impenetrable,imposible pasar por ahi. "
    "En direccion al norte,sur y oeste parece ser posible avanzar. "
    "\n\n");
    add_item("tronco","Uno de los grandes arboles ha caido aqui, al examinarlo "
    "ves que se ha resquebrajado en la base del tronco. "
    "\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j01.c","path");
    add_exit("sur",HAVMAND+"j05.c","path");
    add_exit("oeste",HAVMAND+"j03.c","path");

    ::init();
}


