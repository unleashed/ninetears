//Kryger 2003//
#include "../../path.h"
#include "path.h"
inherit "/std/outside.c";
 void setup()
{
set_short("%^CYAN%^Poblado de Grandhum: %^GREEN%^Entrada%^RESET%^");
set_long(query_short()+"\n"+GRANDP".\n\n");
set_night_long(query_short()+"\n"+GRANDPN".\n\n");
set_light(50);
set_zone("Grandhum");
add_clone(NPC+"habitante_grandhum.c",1); 
set_exit_color("rojo_c");
add_exit("norte",ROOMGRAN"GRAN17.c","road");
add_exit("sudoeste",ROOMGRAN"CFP12.c","road");
add_exit("oeste",ROOMGRAN"GRAN01.c","road");
add_exit("este",ROOMGRAN"GRAN29.c","road");
}