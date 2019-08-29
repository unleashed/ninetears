#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "La jungla se intensifica al norte y al oeste impidiendo el paso. "
    "Tan solo al sur o al este ves posibilidad de pasar. "
    "En la base de uno de los arboles crecen unos pequenyos hongos. "
    "\n\n");
    add_item("hongos","Al mirarlos con detenimiento los identificas "
    "como venenosos, decides dejarlos donde estan."
    "\n");

}
void init()
{
    add_exit("sur",HAVMAND+"p02.c","path");
    add_exit("este",HAVMAND+"j20.c","path");

    ::init();
}


