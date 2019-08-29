//Kryger 2002//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Sur%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	add_clone(NPC+"vaquero_ormerod.c",1);
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("este",ROOMORMPS"pasto_ormerod_77.c","plain");
	add_exit("sudoeste",ROOMORMPS"pasto_ormerod_61.c","plain");
	add_exit("norte",ROOMORMPS"pasto_ormerod_70.c","plain");
}