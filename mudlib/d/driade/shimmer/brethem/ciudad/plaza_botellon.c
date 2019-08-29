/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   add_item("botellas" , "Miles de botellas de ron, whisky, vodka, ginebra y demas.\n");   
   add_smell("aire","Aqui huele a alcohol que te cagas, solo de aspirar profundamente ya notas un gran subidon.\n");
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Plaza del Botellon%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Plaza del Botellon%^RESET%^\n\n"
       "Esta room se me acaba de ocurrir meterla hoy 12-4-2002 conmemorando el pedazo botellon que nos acabamos "
       "de hacer aqui en mi piso yo mis colegas y los colegas de mi colegas. Bueno y no se que mas poner ya que "
       "me tengo que pirar que estos se estan cagando ya en mi xD. Enga, me voi de fiesta por ahi, Montesol, "
       "Egeo, NoSe, PlayaClub y de vuelta pa casita. Bueno, nada mas, barra libre en esta room desde ya...\n\n");

   add_item("barra" , "Una gran barra de madera llena de botellas de Dyc, Negrita, 100 Pippers, Martini, Eristoff "
            "y demas sucedaneos.\n");

   add_clone(BRETHEM+"npcs/gato",random(2));
   add_clone(BRETHEM+"npcs/pajaro",random(0));
   add_clone(BRETHEM+"npcs/guardia",random(3));

add_exit("oeste",    BRETHEM + "mar7.c","standard");
add_exit("sudeste",  BRETHEM + "mar6.c","standard");
add_exit("norte",    BRETHEM + "parque3.c","standard");
add_exit("este",     BRETHEM + "parque4.c","standard");

}
