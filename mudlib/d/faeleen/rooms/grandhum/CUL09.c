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
add_exit("noroeste",ROOMGRAN"CUL07.c","plain");
add_exit("este",ROOMGRAN"CUL12.c","plain");
add_exit("sudoeste",ROOMGRAN"CUL05.c","plain");
}