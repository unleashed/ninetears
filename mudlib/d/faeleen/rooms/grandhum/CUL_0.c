//Kryger 2003//
#include "../../path.h"
#include "path.h"
inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^GREEN%^Cultivos de %^RESET%^CYAN%^Grandhum%^RESET%^");
set_long(query_short()+"\n"+GRANDCC2".\n\n");
set_night_long(query_short()+"\n"+GRANDCCN2".\n\n");
set_zone("cultivos_grandhum");
add_clone(NPC+"agricultor_grandhum.c",random(2));
set_exit_color("azul_c");
add_exit("sudeste",ROOMGRAN"CUL_6.c","plain");
add_exit("sudoeste",ROOMGRAN"CUL_5.c","plain");
}
