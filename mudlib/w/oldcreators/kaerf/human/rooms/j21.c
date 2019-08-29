#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "Los arboles se cierran impidiendo el paso en cualquier direccion, excepto "
    "por donde has venido. Imposible abrirse camino. Hay un tronco caido en el "
    "suelo, es muy grande y parece muy pesado. "
    "\n\n");
    add_item("tronco","Un arbol podrido que ha caido al suelo, ahora solo se "
    "distingue lo que fue el tronco, esta tan podrido que al tocarlo cruje y "
    "se deshace entre tus dedos"
    "\n");

}
void init()
{
    add_exit("este",HAVMAND+"j22.c","path");

    ::init();
}


