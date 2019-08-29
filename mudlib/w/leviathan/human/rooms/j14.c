#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Helechos de un verde brillante crecen en esta zona, lo que te resulta "
    "estranyo, no recuerdas haber visto helechos en otras partes, aunque "
    "resulta un cambio agradable, entre tanto arbol. Puede que les guste mas "
    "el clima o la luz de esta zona dela isla. "
    "\n\n");
    add_item( ({"helecho","helechos"}),"Son de un brillante color verde "
    "y parecen ser delicados, no les ves ninguna utilidad por el "
    "momento. "
    "\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j13.c","path");
    add_exit("sur",HAVMAND+"j15.c","path");
    add_exit("oeste",HAVMAND+"t08.c","path");

    ::init();
}


