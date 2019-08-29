#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Estas en la parte profunda de la jungla. No se ve gran cosa desde aqui, "
    "aunque de vez en cuando ves algun rapido movimiento entre los arboles, "
    "y no puedes distinguir que lo produce, lo cual te causa un cierto desasosiego. "
    "Tal vez no sea buena idea estar mucho por aqui. "
    "\n\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j23.c","path");
    add_exit("sur",HAVMAND+"j30.c","path");
    add_exit("oeste",HAVMAND+"j10.c","path");
    add_exit("este",HAVMAND+"p02.c","path");

    ::init();
}


