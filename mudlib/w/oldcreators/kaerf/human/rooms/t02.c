#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un cruce en la senda, al oeste sigue el camino que lleva al puerto "
    "y al este hay un pequenyo sendero que se introduce en la jungla, al sur "
    "el camino corre paralelo al poblado."
    "\n\n");
    add_item("puerto","Desde aqui casi no se puede ver, solo sabes que es un puerto y tambien ves el mar "
    "\n\n");

    add_exit("oeste",HAVMAND+"t01.c","path");
    add_exit("este",HAVMAND+"j05.c","path");
    add_exit("sur",HAVMAND+"t03.c","path");
}
