#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "El camino se vuelve mas escarpado y tambien mas estrecho al ir bajando. Aqui hay "
    "menos arboles que mas arriba, pero por desgracia ahora hay rocas en el camino "
    "que hacen mas dificil caminar por el.El camino sigue bajando en direccion  "
    "este. "
    "\n\n");
    add_item("rocas","Son rocas de diverso tamanyo y forma que molestan "
    "el paso por la senda, ya de por si no muy transitable. "
    "\n");

}
void init()
{
    add_exit("este",HAVMAND+"j34.c","path");
    add_exit("noroeste",HAVMAND+"j32.c","path");

    ::init();
}


