// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4. Pasillo Lateral.%^RESET%^");
   set_long("Te encuentras en una habitacion del pasillo lateral con unos "
   "techos de gran altura quien disenyo esta torre lo hizo para que alguien "
   "de gran estatura entrase en la misma, alguien mas alto que un troll, y "
   "por lo visto conocedor de la magia por el gran volumen de libros "
   "escritas en algun arcano lenguaje, parace elfico, solo que mas antiguo, "
   "pero si los elfos fueron los primeros seres en escribir, quien pudo ser "
   "el autor de esta escritura ancestral? \n");
   add_clone(TN"npcs/zombie4",random(3));
   
      
   add_exit("oeste",TN4"tn_d_3","road");
   add_exit("norte",TN4"tn_d_5","road");
      
}
