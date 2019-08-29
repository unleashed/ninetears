#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Sigues en la densa jungla, pero tienes la sensacion de que el "
    "suelo esta en ligera pendiente hacia arriba en direccion al "
    "norte, donde parece haber una especie de camino."
    "\n\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j25.c","path");
    add_exit("sudeste",HAVMAND+"j23.c","path");

    ::init();
}


