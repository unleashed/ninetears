#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsla de Havmand : Senda\n\n"
    "Estas en un camino sucio y poco cuidado, construido para poder transportar "
    "las mercancias desde el pequenyo puerto del oeste hasta el poblado que hay "
    "junto al muro del castillo. No parece ser muy transitado dado su aspecto "
    "abandonado, puedes ver que empieza a crecer la hierba incluso en los profundos "
    "surcos dejados por los carros que lo usaban. La impenetrable jungla esta al "
    "norte y el camino continua al este. "
    "\n\n");
    add_item("puerto","Un destartalado puerto se ve al oeste, desde aqui notas "
    "que le hace falta una reparacion cuanto antes, parece llevar mucho tiempo "
    "en desuso.\n");
    add_item("poblado","Un grupito de grotescas viviendas al lado del muro del castillo, "
    "supones que se le puede llamar poblado, aunque da la sensacion de estar desierto "
    "ahora.\n");
    add_item(({"hierba","clumps"}),"Verdes, brillantes matojos de hierba, creciendo "
    "en el camino.\n");
    add_item("jungla","De la jungla solo puedes ver donde empieza, los arboles y matorrales "
    "hacen imposible ver lo que esconde, y no hay manera de entrar desde aqui.\n");

}
void init()
{
   add_exit("puerto",HAVMAND+"d00.c","path");
    add_exit("este",HAVMAND+"t02.c","path");

    ::init();
}
