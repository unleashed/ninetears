inherit "/std/llanura.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Oeste%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	set_zone("pastos_ormerod");
	add_clone(NPC+"ganadero_ormerod.c",1);
	add_clone(NPC+"ganadera_ormerod.c",1);
	add_exit("oeste",ROOMORM"corral_ormerod_25.c","door");
	add_exit("norte",ROOMORM"pasto_ormerod_113.c","door");
	add_exit("este",ROOMORM"pasto_ormerod_119.c","door");
}