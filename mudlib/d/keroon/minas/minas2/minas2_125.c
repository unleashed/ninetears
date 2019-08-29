// Made by valar  12/07/02

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Estas en una zona completamente desconocida para ti. Puedes respirar el aire fresco "
   "que corre entre las grietas del techo. Has tenido suerte en encontrar un lugar asi "
   "para poder descansar y recobrar las fuerzas perdidas, pero no te creas. Muchos han "
   "perecido entre estar paredes victimas de criaturas horrendas. Andate con ojo ""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"cuerpos","esqueletos","restos"}),"Contemplas los restos de seres de diversas razas irreconocibles y destrozados.\n"); 

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("este","d/keroon/minas/minas2/minas2_126.c","standard");
add_exit("oeste","d/keroon/minas/minas2/minas2_124.c","standard");
}
