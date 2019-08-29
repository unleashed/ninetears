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
	add_exit("sudeste",ROOMORM"pasto_ormerod_19.c","door");
	add_exit("oeste",ROOMORM"pasto_ormerod_10.c","door");
	add_exit("este",ROOMORM"pasto_ormerod_20.c","door");
	add_exit("noroeste",ROOMORM"pasto_ormerod_11.c","door");
}