inherit "/std/outside.c"; // s'ha de mirar eksactament el que posar aki //
#include "../path.h"

string long = "%^ORANGE%^Valle del Dragon%^RESET%^\n\n"
      "El Poblado del Valle del Dragon."
	"El poblado esta escondido entre el espeso bosque y protegido"
	"por muralla hecha de arbustos raudos y arboles enhiestos"
	"que superan los 30 metros de altura. En los arboles puedes ver cabanyas"
	"muy tipicas de elfos. Estaran habitadas ?\n\n";

void do_desc(int do_long)
{
	set_short("%^ORANGE%^Valle del Dragon%^RESET%^");
	/* dark_mess para oscuridad */
	set_dark_mess("Te encuentras en el camino que atraviessa el Valle.\n");
	/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^ORANGE%^Valle del Dragon%^RESET%^\n\n"
		"Te mueves a ciegas por el poblado sin saber lo"
		"pisas. Mientras caminas vas chocando con los arboles"
		"al bosque y no crees que sea muy prudente quedarte.\n");
	if (do_long)    // aixo perque serveix ???? //
	set_long(long);
	set_light(50);
	set_zone("poblado_valle");
}

