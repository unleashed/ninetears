//Kryger//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Norte%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	add_clone(NPC+"vaquero_ormerod.c",1);
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("oeste",ROOMORMPN"pasto_ormerod_90.c","plain");
	add_exit("sudeste",ROOMORMPN"pasto_ormerod_101.c","plain");
}