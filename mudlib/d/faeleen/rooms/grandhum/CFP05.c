//Kryger 2003//
#include "../../path.h"
#include "path.h"
inherit "/std/outside.c";
 void setup()
{
set_short("%^RED%^Camino secundario a Grandhum%^RESET%^");
set_long(query_short()+"\n"+GRANDC".\n\n");
set_night_long(query_short()+"\n"+GRANDCN".\n\n");
add_item("flores","Ves unas maravillosas flores de muchos colores, "
        "son las flores pretyus una especie unica en esta zona.\n");          
set_light(50);
set_zone("camino_Grandhum");
set_exit_color("orange");
add_clone(NPC+"comerciante_grandhum.c",2); 
add_exit("sudoeste",ROOMGRAN"CFP04.c","road");
add_exit("norte",ROOMGRAN"CFP06.c","road");
}