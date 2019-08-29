#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Cerca de los limites de la jungla los arboles no parecen crecer tan  "
    "apretados como en la zona mas interna. Aun es posible ver el camino "
    "al oeste, por lo demas solo ves arboles. Un subito movimiento sobre "
    "ti llama tu atencion, pero cuando miras no ves nada raro ali arriba. "
    "\n\n");
    add_item("camino","Desde aqui ves un camino en mal estado al oeste, va de "
    "norte a sur. "
    "\n");
}
void init()
{
    add_exit("oeste",HAVMAND+"t06.c","path");
    add_exit("este",HAVMAND+"j12.c","path");
    add_exit("norte",HAVMAND+"j09.c","path");
    add_exit("sur",HAVMAND+"j13.c","path");

    ::init();
}


