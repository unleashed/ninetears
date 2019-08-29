#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Esta parte de la jungla no parece tan calurosa y humeda. Los arboles "
    "aun son muchos, pero puedes sentir una suave brisa que llega de alguna "
    "parte. Al norte ves una playa, de ahi debe venir la brisa. "
    "\n\n");
    add_feel("brisa","Una gentil brisa llega desde la playa, refrescandote "
    "del agobiante calor de la jungla. "
    "\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j02.c","path");
    add_exit("este",HAVMAND+"j04.c","path");
    add_exit("norte",HAVMAND+"b07.c","path");

    ::init();
}


