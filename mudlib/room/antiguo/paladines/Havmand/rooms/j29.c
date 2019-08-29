#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "La jungla aqui es poco densa, al mirar arriba se puede ver el cielo. "
    "Una fresca brisa sopla suavemente, haciendo esta zona mucho mas seca "
    "que en la parte baja por donde has estado. Los sonidos de la jungla son "
    "mas debiles, pero otro sonido familiar se va haciendo mas fuerte. "
    "Por el suelo hay unas cuantas piedras sueltas de forma redondeada "
    "de diversos tamanyos. "
    "\n\n");
    add_item("piedras",
    "Son piedras de un tono gris rojizo y de aspecto poroso, "
    "todas ellas tienen forma redondeada. "
    "\n");
    add_feel(({"piedra","piedras"}),"Las piedras son rugosas al tacto "
    "y al pasarles la mano por encima suena un suave crujido. ");
    add_sound("jungla","Los sonidos de los pajaros suenan mas debiles aqui, "
    "pero mas claros al no ser apagados por la densidad de la jungla, puedes "
    "distinguir cada pajaro por separado. "
    "\n");
    add_sound(({"familiar","mar","aire","ambiente"}),"Puedes oir el sonido de "
    "las olas rompiendo en alguna parte. "
    "\n");
    add_feel(({"brisa","aire"}),"Es fresca, y resulta placentero sentirla "
    "en la cara despues de atravesar la asfixiante jungla."
    "\n");
}
void init()
{
    add_exit("noreste",HAVMAND+"j28.c","path");
    add_exit("noroeste",HAVMAND+"h00.c","path");

    ::init();
}





