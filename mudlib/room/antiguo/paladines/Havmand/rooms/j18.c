#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Zona densa de la jungla. No hay forma de internarse entre los arboles "
    "de manera que las unicas salidas te llevan de vuelta al campamento "
    "pirata. No parece una buena idea pasearse mucho por el campamento, "
    "asi que mejor ir con cuidado. "
    "\n\n");

}
void init()
{
    add_exit("norte",HAVMAND+"p02.c","path");
    add_exit("este",HAVMAND+"p04.c","path");


    ::init();
}


