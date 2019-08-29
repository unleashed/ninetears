#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "Estas en la parte este del precario puente colgante. La jungla continua "
    "por todas partes, y parece cerrarse mas que nunca. Los arboles te rodean "
    "de tal forma que solo puedes seguir al este o volver sobre tus pasos. "
    "\n\n");
    add_item( ({"puente","colgante"}),"Es un puente hecho con lianas cortadas "
    "de la jungla. Cruza una profunda grieta, esperemos que sea mas resistente "
    "de lo que aparenta. "
    "\n");
    add_item("grieta","Es una profunda grieta en el suelo,demasiado ancha "
    "para saltarla. No hay otra opcion que usar el puente para cruzar. "
    "\n");
    add_item( ({"liana","lianas"}),"Largas lianas cuelgan de alguno de los "
    "arboles. Parecen muy resistentes y utiles por su semejanza a cuerdas. "
    "Obviamente quien construyo el puente con ellas pensaba lo mismo. "
    "\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j09.c","path");
    add_exit("este",HAVMAND+"j16.c","path");

    ::init();
}


