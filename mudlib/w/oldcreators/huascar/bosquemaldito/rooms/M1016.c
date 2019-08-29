//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^GREEN%^Bosque maldito%^RESET%^");
set_long("%^GREEN%^Bosque maldito%^RESET%^\n\n El bosque aqui es un poco mas oscuro que en otras partes, "
	 "hay algo indescriptible en el aire que te da una sensacion de ser observado, tal "
	 "vez sea aconsejable buscar en las sombras por si acecha algun ser hostil. Los "
 	 "arboles son mas altos de lo normal y curiosamente apenas hay hierbas o helechos. "
	 "La fauna escasea por estas tierras.\n\n");
		
set_light(50);
set_zone("bosque");
add_clone(NPC"lobo.c",random(5)-3);
add_clone(NPC"mosquito.c",random(5)-3);
add_clone(NPC"oso.c",random(5)-3);
add_exit("noroeste",CHA"M1115.c","road");
add_exit("sur",CHA"M0916.c","road");
}