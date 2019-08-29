inherit "/std/room.c";
#include "../../path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Esquiladora%^RESET%^.");
	set_long("%^BOLD%^BLUE%^Esquiladora%^RESET%^.\n"
	"Entramos en una sala grande y espaciosa, vemos en un rincon una pila "
	"de lana, mirando de reojo alcanzamos a ver una banqueta detras de "
	"unas ovejas, no hay nadie, parece que haya salido el due�o fuera."
	"Observamos que la sala esta echa de madera, y tiene varios ventanales "
	"por donde entra la luz del sol. Esta bastante iluminado.\n\n");
	set_night_long("%^BOLD%^BLUE%^Esquiladora%^RESET%^.\n"
	"Entramos en una sala grande y espaciosa, vemos en un rincon una pila "
	"de lana, mirando de reojo alcanzamos a ver una banqueta detras de "
	"unas ovejas, no hay nadie, parece que el due�o se fue a dormir."
	"Observamos que la sala esta echa de madera, y tiene varios ventanales "
	"por donde entra la luz de la luna. Esta bastante oscuro.\n\n");

	set_ligth(50);
	add_exit("norte",ROOMORM"pueblo_ormerod_3.c","door");
}