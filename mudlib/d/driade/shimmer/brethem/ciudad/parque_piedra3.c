/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque de la Piedra%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque de la Piedra%^RESET%^\n\n"
            "En el centro mismo del parque, una gigantesca piedra ovalada medio enterrada llama tu "
            "atencion. Se dice que la piedra iba a formar parte de la estatua a Shimmer que hay en "
            "la ciudad, supuestamente era esta la piedra de la cual se iba a esculpir dicha obra, pero "
            "cuando la transladaban se les escurrio y la piedra se clavo en la tierra, como quedaba bien "
            "la dejaron y este paso a llamarse el Parque de la Piedra.\n <- ke kutre la historia xD pero "
            "son las 3 de la manyana y estoy cansao de pensar xD\n\n");


   add_item(({"piedra","estatua"}),
           "   Es una gran roca ovalada de un material blanco brillante en el que incluso puedes ver tu "
           "imagen reflejada cuando te acercas, esta era la roca destinada a formar parte del monumento a "
           "Shimmer, pero se quedo aqui clavada por un descuido de los que la transportaban.\n");


  
   add_clone(BRETHEM + "npcs/borracho",random(2)-1);  
   add_clone(BRETHEM + "npcs/perro",random(2)-1); 
   add_clone(BRETHEM + "npcs/ciudadano",random(2)-1); 


add_exit("noreste",        BRETHEM + "parque_piedra2.c","standard");
add_exit("este",           BRETHEM + "parque_piedra1.c","standard");
add_exit("sur",            BRETHEM + "parque_piedra4.c","standard");


}
