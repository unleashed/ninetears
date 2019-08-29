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
	add_clone(NPC+"ganadero_ormerod.c",1);
	add_clone(NPC+"ganadera_ormerod.c",1);
	add_exit("noroeste",ROOMORM"pasto_ormerod_1.c","door");
	add_exit("sudeste",ROOMORM"pasto_ormerod_9.c","door");
	add_exit("noreste",ROOMORM"pasto_ormerod_10.c","door");
	add_exit("oeste",ROOMORM"camino_ormerod_3.c","door");
}