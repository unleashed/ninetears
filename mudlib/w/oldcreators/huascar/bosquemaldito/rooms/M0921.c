//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^BOLD%^GREEN%^Claro en el bosque%^RESET%^");
set_long("%^BOLD%^GREEN%^Claro en el bosque%^RESET%^\n\nEstas en uno de los escasos claros que hay en este "
	 "tupido bosque. Aqui puedes notar con facilidad el paso de la brisa puesto "
	 "que no se encuentra obstaculizada por ningun arbol. La hierba crece con "
 	 "facilidad por lo que es frecuente ver algun animal pastando tranquilamente "
	 "en las cercanias.\n\n");
		
set_light(50);
set_zone("maldito");
add_clone(NPC"carnero.c",random(3)-1);
add_clone(NPC"vaca.c",random(3)-1);
add_exit("este",MAL"M0922.c","road");
add_exit("noroeste",MAL"M1020.c","road");
}
