// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos sus "
        "habitantes son humanos, aunque se puede ver algun que otro enano o "
            "elfo.\n"
            "Hay una casa al sur, con una puerta de madera enorme. La casa "
            "parece no estar habitada ya que esta mal estado de consevacion."
            "\n");

   add_exit("noreste" ,ANDUAR"cruce0613.c","road");
   add_exit("oeste"   ,ANDUAR"cruce0711.c","road");
   add_exit("este"    ,ANDUAR"cruce0713.c","road");
   add_exit("sudeste" ,ANDUAR"cruce0813.c","road");
    add_exit("south", "/d/clanes/marmion/rooms/sala","door");
   modify_exit("south",({"function","enter"})); 

   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
int enter() 
{ 
    if(TP->query_group_name() != "Marmion") 
    { 
        notify_fail("La puerta es muy pesada y parece estar atrancada.\n"
                    "Ni el mejor ladron podria forzarla.\n"); 
        return 0; 
    } 
 
   tell_object(this_player(),"Abres la puerta de tu casa rapidamente para "
           "que nadie te descubra.\n"); 
    tell_room(this_object(), this_player()->query_cap_name()+  
      " abre una puerta con una llave magica, entra y la cierra de un "
      "portazo.\n", ({this_player()}) ); 
    return 1; 
} 

