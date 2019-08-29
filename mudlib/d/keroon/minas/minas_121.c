// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "vagoneta.h"
void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en la amplia entrada de las minas, de la cual parten diversos railes hacia el interior destinados a la circulacion de las vagonetas que trasportan los minerales y piedras preciosas extraidos del interior de las minas. Ves a bastantes guardias destinados a controlar la llegada de minerales y piedras preciosas, asi como su distribucion a los diversos esclavos y mineros que, con carretillas, se dedican a descargar las vagonetas y posteriormente trasladar su contenido a las forjas.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_exit("oeste",MINAS+"minas_120.c","standard");
add_exit("norte",MINAS+"minas_91.c","standard");
add_exit("este",MINAS+"minas_122.c","standard");
}
