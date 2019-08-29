#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Incluso estando tan cerca de la playa, los arboles crecen gigantescos "
    "y muy arrimados unos a otros,  se hace dificil moverse. Todavia puedes "
    "oler el salitre en el aire, Pero la playa casi ha desaparecido de tu "
    "vista. "
    "\n\n");
    add_item("playa","La playa esta al este. Desde aqui lo unico que "
    "puedes ver es que su arena es blanca, y el mar se ve azul. "
    "\n");

}
void init()
{
    add_exit("este",HAVMAND+"b05.c","path");
    add_exit("oeste",HAVMAND+"j21.c","path");

    ::init();
}


