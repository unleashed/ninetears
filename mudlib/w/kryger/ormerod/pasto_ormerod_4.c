inherit "/std/llanura.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Oeste%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	set_zone("pastos_ormerod");
	add_exit("noreste",ROOMORM"pasto_ormerod_8.c","plain");
	add_exit("sudeste",ROOMORM"pasto_ormerod_7.c","plain");
}