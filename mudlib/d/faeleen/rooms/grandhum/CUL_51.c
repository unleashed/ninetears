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
set_exit_color("azul_c");
add_exit("oeste",ROOMGRAN"CUL_50.c","plain");
add_exit("norte",ROOMGRAN"CUL_47.c","plain");
add_exit("sudeste",ROOMGRAN"CUL_55.c","plain");
add_exit("sudoeste",ROOMGRAN"CUL_54.c","plain");
}
