
#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Esto parece ser otro punto muerto. La jungla es menos densa aqui, "
    "vislumbras la playa al norte, pero no encuentras ningun camino para "
    "llegar a ella. "
    "\n\n");
    add_item("playa","Desde aqui puedes ver la arena blanca y no mucho "
    "mas. "
    "\n");
    add_smell("aire","Hay un ligero toque salado en el aire, se nota "
    "la cercania del mar. "
    "\n");
}
void init()
{
    add_exit("este",HAVMAND+"j03.c","path");

    ::init();
}



