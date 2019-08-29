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
	add_exit("este",ROOMORMPN"pasto_ormerod_65.c","plain");
	add_exit("sur",ROOMORMP"entrada_a_pastos_2.c","plain");
	add_exit("norte",ROOMORMPN"pasto_ormerod_58.c","plain");
}