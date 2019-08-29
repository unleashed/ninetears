#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : playa\n\n"
    "   La larga playa de arena blanca se extiende a norte y sur. Es algo "
    "curioso, parece que en esta zona de la playa hay mas conchas que en "
    "ninguna otra. Al caminar sobre ellas emiten un crujido muy sonoro, "
    " en caso de haber alguien cerca escuchando, seguro que ya sabe de "
    "de tu presencia."
    "\n\n");
    add_item(({"concha","conchas"}),"Pilas de conchas de todos los tamanyos, formas "
    "y colores, no piensas que se hayan amontonado de esta manera de forma natural. "
    "  No puedes evitar caminar sobre ellas, tal es la cantidad, parece como "
    "si alguien se hubiera tomado mucho trabajo para saber cuando alguien "
    "se aproxima. Deberias estar atento.\n");

}
void init()
{
    add_exit("norte",HAVMAND+"b01.c","path");
    add_exit("sur",HAVMAND+"b03.c","path");
    add_exit("oeste",HAVMAND+"p01.c","path");


    ::init();
}

