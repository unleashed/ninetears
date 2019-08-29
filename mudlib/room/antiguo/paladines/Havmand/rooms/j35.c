#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "El camino baja describiendo una espiral cada mas pendiente y estrecho. "
    "Casi han desaparecido los arboles, reemplazados por rocas. Mirando en derredor "
    "te das cuenta que estas caminando entre dos grandes rocas que forman un profundo "
    "valle. En las rocas crece musgo y liquenes , el ambiente es muy humedo aqui."
    "\n\n");
    add_item( ({"roca","rocas","valle","grandes rocas"}),"Dos enormes rocas de caras lisas que parecen cortadas a cuchillo y enfrentadas entre si."
    " Estan cubiertas de musgo y liquen. "
    "\n");
//    add_item("liquen","Scaly, frondlike plants growing on the rock face. "
//    "\n");
    add_item("musgo","Suave musgo verde que crece pegado a la pared de roca. "
    "\n");

}
void init()
{
    add_exit("noroeste",HAVMAND+"j36.c","path");
    add_exit("sudoeste",HAVMAND+"j34.c","path");

    ::init();
}


