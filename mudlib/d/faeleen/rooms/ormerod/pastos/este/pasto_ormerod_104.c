//Kryger 2002//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Este%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	add_clone(NPC+"vaquero_ormerod.c",1);
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("sudoeste",ROOMORMPE"pasto_ormerod_98.c","plain");
	add_exit("norte",ROOMORMPE"pasto_ormerod_105.c","plain");
	add_exit("este",ROOMORMPE"pasto_ormerod_108.c","plain");
	add_exit("sur",ROOMORMPE"pasto_ormerod_103.c","plain");
}