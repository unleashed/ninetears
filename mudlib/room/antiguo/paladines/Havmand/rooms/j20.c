#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Esta parte de la jungla se encuentra cerca del campameto pirata, seria "
    "prudente moverse con cuidado. A ellos no les gustan los estranyos, y el refugio "
    "de su capitan queda justo al este de aqui. "
    "\n\n");

}
void init()
{
    add_exit("este",HAVMAND+"p01.c","path");
    add_exit("oeste",HAVMAND+"j19.c","path");

    ::init();
}


