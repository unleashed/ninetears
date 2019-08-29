#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Los arboles parecen cerrarse en torno a ti, pero aun puedes abrirte "
    "paso entre la maranya de ramas y lianas. De todas formas, al este esta "
    "totalmente bloqueado, mejor ni intentar esa direccion. "
    "Al oeste ves lo que parece un camino mas o menos transitable, pero no "
    "se ve bien desde aqui. "
    "\n\n");
    add_item( ({"rama","ramas"}),"Las ramas estan retorcidas y liadas unas con otras, "
    "estan cubiertas de liquenes y musgo. "
    "\n");
    add_item( ({"liana","lianas"}),"Largas y delgadas, cuelgan desde muy alto, "
    "y parecen estar firmemente sujetas a donde quiera que esten enganchadas. "
    " Aunque podrian ser utiles, estas son demasiado finas para darles un uso.\n"
    "\n");
    add_item("camino","Aunque desde aqui no lo ves con claridad, parece una senda "
    "hecha para el transito de carros o vagonetas."
    "\n");
}
void init()
{
    add_exit("norte",HAVMAND+"j04.c","path");
    add_exit("sur",HAVMAND+"j06.c","path");
    add_exit("oeste",HAVMAND+"t02.c","path");

    ::init();
}


