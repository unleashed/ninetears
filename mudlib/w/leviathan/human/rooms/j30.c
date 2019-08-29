#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Estas en un sendero que desciende suavemente. El suelo esta cubierto "
    "por hojas que amortiguan tus pisadas, y te parece oir el sonido de agua "
    "cayendo en alguna parte cercana. Los arboles parecen tener mas musgo por "
    "esta zona. "
    "\n\n");
    add_sound(({"agua","liquido"}),"Definitivamente es el ruido de agua "
    "al caer, pero aunque suena cercano no ves agua por ningun lado. "
    "\n");
    add_item("musgo","Es un musgo que crece en los arboles, en esta zona parece "
    "mas vigoroso y abundante que en otras partes de la jungla. "
    "\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j16.c","path");
    add_exit("sudoeste",HAVMAND+"j31.c","path");

    ::init();
}


