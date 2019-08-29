//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^BOLD%^BLACK%^Charca%^RESET%^");
set_long("%^BOLD%^BLACK%^Charca%^RESET%^\n\n El agua estancada te rodea causandote unas nauseas "
	 "insoportable. En este ambiente insano solo pueden sobrevivir insectos y sanguijuelas. "
	 "Hay restos de troncos putrefactos con moho adherido y algunos helechos en no muy "
 	 "buen estado. Definitivamente no es un lugar que elegirias para hacer una merienda "
	 "campestre.\n\n");
		
set_light(50);
set_zone("charca");
add_clone(NPC"babosa.c",random(4)-2);
add_clone(NPC"mosquito.c",random(4)-2);
add_clone(NPC"mariposa.c",random(4)-2);
add_clone(NPC"culebra.c",random(4)-2);
add_clone(NPC"sapo.c",random(4)-2);
add_exit("oeste",CHA"M0308.c","road");
add_exit("noroeste",CHA"M0408.c","road");
add_exit("norte",CHA"M0409.c","road");
add_exit("noreste",CHA"M0410.c","road");
add_exit("este",CHA"M0310.c","road");
add_exit("sudeste",CHA"M0210.c","road");
add_exit("sur",CHA"M0209.c","road");
add_exit("sudoeste",CHA"M0208.c","road");
}