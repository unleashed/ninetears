#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "   Hay conchas esparcidas por gran parte de la arena en esta zona de la "
    "playa y no puedes evitar que suenen sonoros crujidos al caminar. "
    " La alfombra de conchas es mas tupida en la parte cercana a los arboles "
    "que limitan con la playa, lo cual resulta estranyo, ya que el agua parece "
    "no llegar tan arriba ni aun en las mareas. "
    "\n\n");
    add_item("conchas","Conchas de todos los tamanyos, colores y formas, y muchas "
    "de ellas rotas. Parecen haber sido puestas aqui premeditadamente para que "
    "actuen como alarma sonora. \n");
    add_item(({"arbol","arboles"}),"Los arboles de la cercana jungla son altos "
    "y con anchos troncos que crecen muy juntos, un sendero comienza entre ellos "
    "justo aqui. \n");
}
void init()
{
    add_exit("norte",HAVMAND+"b03.c","path");
    add_exit("sur",HAVMAND+"b05.c","path");
    add_exit("oeste",HAVMAND+"p05.c","path");

    ::init();
}
