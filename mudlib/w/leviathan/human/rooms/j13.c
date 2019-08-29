#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "No estas lejos de la aldea, es realmente pesado moverse por la jungla, "
    "asfixiante por el calor y agobiante por la dificultad de movimientos. "
    "Las ramas mas bajas te golpean si no tienes cuidado."
    "\n\n");
    add_item( ({"rama","ramas"}),"Algunas de las ramas bajas son muy flexibles, "
    "y al volver a su posicion natural te golpean segun vas pasando. "
    "\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"t07.c","path");
    add_exit("norte",HAVMAND+"j11.c","path");
    add_exit("sur",HAVMAND+"j14.c","path");
    add_exit("noreste",HAVMAND+"j12.c","path");

    ::init();
}


