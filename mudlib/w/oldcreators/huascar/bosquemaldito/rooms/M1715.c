//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^BOLD%^GREEN%^Zona selvatica%^RESET%^");
set_long("%^BOLD%^GREEN%^Zona selvatica%^RESET%^\n\nEsta zona inexplicablemente es mas calurosa "
	 "que el resto y junto con la constante humedad da lugar a que la vegetacion sea "
	 "selvatica. La fauna local es acorde con el terreno por lo que un torrente de sonidos "
 	 "de las mas diversas criaturas llega a tus oidos. Notas un cierto sofoco por las "
	 "condiciones climaticas pero poco a poco te vas acostumbrando a ella.\n\n");
		
set_light(50);
set_zone("selva");
add_clone(NPC"tigre.c",random(4)-2);
add_clone(NPC"mono.c",random(4)-1);
add_clone(NPC"mariposa.c",random(3)-1);
add_clone(NPC"culebra.c",random(3)-1);
add_clone(NPC"pajaro.c",random(3)-1);
add_exit("este",MAL"M1716.c","road");
add_exit("sudoeste",MAL"M1614.c","road");
}