#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Bien, estas en un punto muerto, la jungla aqui es demasiado espesa y "
    "solo puedes volver por donde has venido. Imposible abrir una senda "
    "en ninguna direccion. "
    "\n\n");

}
void init()
{
    add_exit("este",HAVMAND+"b01.c","path");

    ::init();
}


