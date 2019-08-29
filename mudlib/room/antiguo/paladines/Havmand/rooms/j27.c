#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "El camino se vuelve mas estrecho y escarpado aqui.\n"
    "En el suelo hay unos cuantos troncos de arboles caidos que forman "
    "una especie de escalera. Las lianas, que antes colgaban de esos arboles, "
    "ahora resultan de gran ayuda como asidero para subir o bajar en esta "
    "zona empinada. "
    "\n\n");
    add_item("lianas",
    "Las lianas enrolladas a los troncos son anchas y muy fibrosas, lo que "
    "las hace resistentes, intentas arrancar una de ellas pero esta firmemente "
    "anclada al tronco. "
    "\n");
    add_item(({"tronco","troncos","arbol"}),"Los arboles caidos se han ido "
    "asentando en el suelo y unos contra otros,de tal forma que son inamovibles. "
    "\n");

add_item("escalera","Los arboles y las lianas forman una caprichosa escalera "
    "natural por la que se puede subir o bajar en este trecho.  \n");
//add_item("ravine","This small indentation in the ground could be dangerous to your "
//"health, if you fell in.  You decide it's best to stay away from it.  \n");
}
void init()
{
    add_exit("oeste",HAVMAND+"j26.c","path");
    add_exit("sudeste",HAVMAND+"j28.c","path");

    ::init();
}



