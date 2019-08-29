#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un camino sucio y descuidado que corre paralelo a un grotesco poblado "
    "construido al oeste, bajo la muralla de un castillo. Al este esta la inevitable "
    "y odiosa jungla... algun dia deberas encontrar la manera de salir de esta isla. "
    "El camino del oeste conduce a una de las pocas viviendas del poblado, "
    "a su entrada tiene un pequenyo jardin. "
    "\n\n"); 
    add_item("jardin","Un cuidado jardin crece a la entrada de la vivienda, "
    "esta lleno de hierbas aromaticas. \n");
    add_item("herbs","Una coleccion de hierbas y plantas conocidas por su poder "
    "curativo. aunque  otras muchas no las reconoces.\n");

}
void init()
{
    add_exit("norte",HAVMAND+"t06.c","path");
    add_exit("sur",HAVMAND+"t08.c","path");
    add_exit("oeste",HAVMAND+"v05.c","path");
    add_exit("este",HAVMAND+"j13.c","path");

    ::init();
}


