//Kryger 2002//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Este%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS2".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN2".\n\n");
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("sudoeste",ROOMORMPE"pasto_ormerod_103.c","plain");
	add_exit("noreste",ROOMORMPE"pasto_ormerod_118.c","plain");
	add_exit("sudeste",ROOMORMPE"pasto_ormerod_117.c","plain");
	add_exit("oeste",ROOMORMPE"pasto_ormerod_104.c","plain");
}