//Leviathan
inherit "/std/outside.c";
#include "./path.h"

void setup()
{
set_short(DESC_CORTA);
set_long(DESC_LARGA);
		
set_light(50);
set_zone(ZONA);
//add_clone(NPC"bitxo.c",random(3)-1);
//add_clone(NPC"otrobitxo.c",random(3)-1);
add_exit("norte","ejemplo.c","road");
add_exit("este","ejemplo.c","road");
}
