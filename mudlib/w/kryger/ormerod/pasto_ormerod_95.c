inherit "/std/llanura.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Oeste%^RESET%^.");
	set_long(query_short()+"\n"+PASTOS1".\n\n");
	set_night_long(query_short()+"\n"+PASTOSN1".\n\n");
	add_property("luz_real",50);
	set_zone("pastos_ormerod");
	add_clone(NPC"ganadero_ormerod.c",1);
	add_clone(NPC"ganadera_ormerod.c",1);
	add_exit("sudoeste",ROOMORM"pasto_ormerod_88.c","door");
	add_exit("noroeste",ROOMORM"pasto_ormerod_89.c","door");
	add_exit("noreste",ROOMORM"pasto_ormerod_100.c","door");
	add_exit("este",ROOMORM"corral_ormerod_20.c","door");
}