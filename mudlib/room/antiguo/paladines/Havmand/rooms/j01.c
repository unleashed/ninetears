#include "path.h"
inherit HERE+"jungle.c";

void setup()
{
    set_long("\nIsla de Havmand : Jungla\n\n"
    "La jungla parece ser menos densa aqui. Puedes distinguir, entre los arboles, "
    "una playa al oeste, y el mar al norte, pero no encuentras ninguna via para ir "
    "en esas direcciones. "
    "\n\n");
    add_item("playa","No se ve bien desde aqui, pero parece estar cubierta "
    "de arena blanca. "
    "\n");
    add_item("mar","Puedes ver la espuma de las olas al romper, pero no "
    "encuentras un lugar desde el que puedas ver con claridad. "
    "\n");
    add_sound("mar","Escuchando con atencion oyes el ruido de olas rompiendo contra "
    "las rocas y los cantos de gaviotas. "
    "\n");

}
void init()
{
    add_exit("sur",HAVMAND+"j04.c","path");

    ::init();
}


