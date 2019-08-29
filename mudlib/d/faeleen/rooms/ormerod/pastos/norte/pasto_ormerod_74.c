//Kryger//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Norte%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS2".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN2".\n\n");
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("sudeste",ROOMORMPN"pasto_ormerod_80.c","plain");
	add_exit("sudoeste",ROOMORMPN"pasto_ormerod_65.c","plain");
	add_exit("noreste",ROOMORMPN"pasto_ormerod_81.c","plain");
}