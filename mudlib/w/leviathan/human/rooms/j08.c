#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Los arboles en esta cena zona crecen muy juntos unos de otros. No hay "
    "manera de moverse mas que en un par de direcciones, y parece que en "
    " ambos sentidos encontraras mas jungla. "
    "\n\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j07.c","path");
    add_exit("noroeste",HAVMAND+"j06.c","path");

    ::init();
}



