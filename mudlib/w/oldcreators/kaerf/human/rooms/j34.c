#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "En esta zona hay pocos arboles, aunque sigue siendo dificil moverse. "
    "Al menos la senda es facil de seguir y uno no puede perderse, de todas "
    "formas se va haciendo mas estrecha, sigue hacia abajo en direccion noreste. "
    "\n\n");


}
void init()
{
    add_exit("oeste",HAVMAND+"j33.c","path");
    add_exit("noreste",HAVMAND+"j35.c","path");

    ::init();
}


