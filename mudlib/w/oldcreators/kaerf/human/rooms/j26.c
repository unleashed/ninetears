#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Estas en una pequenya senda abierta en la jungla, parece ir subiendo "
    "haciendo una espiral, y se ve muy poco usada. Aunque estas a mas altura "
    "sigues rodeado de arboles."
    "\n\n");
//    add_sound("rustling","You really, really hope its the sounds of birds"
//    "you can hear scrummaging through the leaves. "
//    "\n");
//    add_item("leaf-litter","Piles of fallen leaves make excellent homes for "
//    "various bugs and crawly things. "
//    "\n");

}
void init()
{
    add_exit("este",HAVMAND+"j27.c","path");
    add_exit("sudoeste",HAVMAND+"j25.c","path");

    ::init();
}


