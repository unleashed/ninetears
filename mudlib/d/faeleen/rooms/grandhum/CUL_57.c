//Kryger 2003//
#include "../../path.h"
#include "path.h"
inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^GREEN%^Cultivos de %^RESET%^CYAN%^Grandhum%^RESET%^");
set_long(query_short()+"\n"+GRANDCC1".\n\n");
set_night_long(query_short()+"\n"+GRANDCCN1".\n\n");
set_zone("cultivos_grandhum");
add_clone(NPC+"agricultora_grandhum.c",random(2));
set_exit_color("azul_c");
add_exit("noroeste",ROOMGRAN"CUL_52.c","plain");
add_exit("sudoeste",ROOMGRAN"CUL_62.c","plain");
}
