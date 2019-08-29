#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
   set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un camino sucio y descuidado que corre paralelo a un grotesco poblado "
    "construido al oeste, bajo la muralla de un castillo. Al este esta la inevitable "
    "y odiosa jungla... algun dia deberas encontrar la manera de salir de esta isla. "
    "El camino del oeste conduce a una de las pocas viviendas del poblado. "
    "\n\n");
 
}
void init()
{
    add_exit("norte",HAVMAND+"t04.c","path");
    add_exit("sur",HAVMAND+"t06.c","path");
    add_exit("oeste",HAVMAND+"v03.c","path");
    add_exit("este",HAVMAND+"j09.c","path");

    ::init();
}

