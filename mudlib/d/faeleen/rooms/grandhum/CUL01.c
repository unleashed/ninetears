//Kryger 2003//
#include "../../path.h"
#include "path.h"
inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^GREEN%^Cultivos de %^RESET%^CYAN%^Grandhum%^RESET%^");
set_long(query_short()+"\n"+GRANDCC".\n\n");
set_night_long(query_short()+"\n"+GRANDCCN".\n\n");
set_zone("cultivos_grandhum");
set_exit_color("azul_c");
add_exit("noreste",ROOMGRAN"CUL04.c","plain");
add_exit("sudeste",ROOMGRAN"CUL03.c","plain");
}