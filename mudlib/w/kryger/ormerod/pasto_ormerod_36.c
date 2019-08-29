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
	add_exit("sudoeste",ROOMORM"pasto_ormerod_29.c","door");
	add_exit("sur",ROOMORM"entrada_a_pastos_1.c","door");
	add_exit("noreste",ROOMORM"pasto_ormerod_42.c","door");
	add_exit("noroeste",ROOMORM"pasto_ormerod_30.c","door");
}