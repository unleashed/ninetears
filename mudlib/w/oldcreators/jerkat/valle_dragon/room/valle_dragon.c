inherit "/std/outside.c";
#include "../path.h"

string long = " %^RED%^Valle del Dragon%^RESET%^ \n\n"
      "El Valle parece abrirse entre dos montanyas de gran embergadura.\n"
	"Estas en un pequenyo camino que atraviesa el denso bosque"
	"y ves al margen derecho un pequenyo riachuelo que te acompanya"
	"a lo largo del camino ascendiente hasta el fondo del valle.\n "
	"Debes apresurarte si no quieres que la noche se te heche encima\n\n";

void do_desc(int do_long)
{
	set_short("%^RED%^Valle del Dragon%^RESET%^ ");
	/* dark_mess para oscuridad */
	set_dark_mess("Te encuentras en el camino que atraviessa el Valle.\n");
	/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^RED%^Valle del Dragon%^RESET%^ \n\n"
		"Estas en medio de un Bosque muy denso y apenas "
		"puedes encontrar el camino. La noche ha llegado "
		"al bosque y no crees que sea muy prudente quedarte "
		"aqui. Hay peligros que te acechan\n");
	if (do_long)
	set_long(long);
	set_light(40);
	set_zone("valle_dragon");
}

