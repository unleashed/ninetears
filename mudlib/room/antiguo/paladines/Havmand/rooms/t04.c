#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
   set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un camino sucio y descuidado que corre paralelo a un grotesco poblado "
    "construido al oeste, bajo la muralla de un castillo. Al este esta la inevitable "
    "y odiosa jungla... algun dia deberas encontrar la manera de salir de esta isla. "
    "El camino del oeste conduce a una de las pocas viviendas del poblado, "
    "en su fachada un tosco cartel dice: Tienda. "
    "\n\n");

    

    add_exit("norte",HAVMAND+"t03.c","path");
    add_exit("sur",HAVMAND+"t05.c","path");
    add_exit("oeste",HAVMAND+"v02.c","path");
    add_exit("este",HAVMAND+"j07.c","path");
}

