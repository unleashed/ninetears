#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Definitivamente el camino te lleva hacia arriba, para seguir subiendo "
    "ahora debes ir hacia el noreste. Aunque todo es igual, lleno de arboles "
    "con musgo y liquenes cubriendo sus troncos, piensas que subiendo tal vez "
    "encuentres algo diferente. "
    "\n\n");

}
void init()
{
    add_exit("noreste",HAVMAND+"j26.c","path");
    add_exit("sur",HAVMAND+"j24.c","path");

    ::init();
}


