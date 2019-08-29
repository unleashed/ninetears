#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Esta es un zona muy espesa y es casi imposible ver a traves de los "
    "arboles y cuesta abrirse paso. El camino que atraviesa la aldea esta "
    "al oeste, puedes tambien ir al norte siguiendo la jungla, pero cualquier "
    "otra direccion es imposible. "
    "\n\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"t09.c","path");
    add_exit("norte",HAVMAND+"j14.c","path");

    ::init();
}


