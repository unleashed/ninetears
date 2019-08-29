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
add_exit("oeste",ROOMGRAN"CUL_36.c","plain");
add_exit("noroeste",ROOMGRAN"CUL_30.c","plain");
add_exit("noreste",ROOMGRAN"CUL_31.c","plain");
add_exit("este",ROOMGRAN"CUL_38.c","plain");
}
