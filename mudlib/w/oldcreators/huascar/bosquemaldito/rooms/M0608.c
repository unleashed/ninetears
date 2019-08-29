//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^GREEN%^Camino hacia la charca%^RESET%^");
set_long("%^GREEN%^Camino hacia la charca%^RESET%^\n\nEstas en el viejo camino hacia la charca. "
	 "Aunque aun no has llegado a ella la humedad es considerable y te parece oir "
	 "el croar de alguna rana a lo lejos. La vegetacion es la tipica de un lugar "
 	 "asi, es decir mucho matorral y esporadicamente algun que otro arbol de hoja "
	 "caduca.\n\n");
		
set_light(50);
set_zone("maldito");
add_clone(NPC"sanguijuela.c",random(3)-1);
add_clone(NPC"rata.c",random(3)-1);
add_exit("sur",MAL"M0508.c","road");
add_exit("norte",MAL"M0708.c","road");
}
