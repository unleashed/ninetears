//Kryger 2002//
inherit "/std/llanura.c";
#include "../../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Sur%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS3".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN3".\n\n");
	add_clone(NPC+"bichos_ormerod.c",3);
	set_zone("pastos_ormerod");
	set_exit_color("verde_c");
	add_exit("noreste",ROOMORMPS"pasto_ormerod_68.c","plain");
	add_exit("norte",ROOMORMPS"pasto_ormerod_61.c","plain");
	add_exit("noroeste",ROOMORMPS"pasto_ormerod_54.c","plain");
}