//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Calle Principal %^RESET%^.");
	set_long(query_short()+"\n"+CALLEP".\n\n");
	set_night_long(query_short()+"\n"+CALLEPN".\n\n");
	set_zone("pueblo_ormerod");
	day_clone(NPC"npcs_rongrond.c",2);
	night_clone(NPC"rata.c",random(1));
	set_exit_color("amarillo_c");
	add_exit("noreste",ROOMORMP"cruce_ormerod.c","standard");
	add_exit("oeste",ROOMORMP"pueblo_ormerod_1.c","standard");
	add_exit("este",ROOMORMP"pueblo_ormerod_3.c","standard");
	add_exit("noroeste",ROOMORMP"entrada_a_pastos_1.c","standard");
}