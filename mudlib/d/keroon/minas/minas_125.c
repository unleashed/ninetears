// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "vagoneta.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual discurren una gran cantidad de railes provenientes de distintos tuneles que se cruzan entre ellos y desaparecen hacia otros corredores. Debido a la intensa circulacion de vagonetas que se produce en la zona se ha habilitado una antigua caseta de herramientas para que los guardianes encargados controlen mediante un sofisticado e ingenioso sistema de agujas el desplazamiento de vagonetas por los diversos railes, sin que se produzca ningun accidente.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_clone(NPCSMINAS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_124.c","standard");
add_exit("norte",MINAS+"minas_95.c","standard");
add_exit("noreste",MINAS+"minas_96.c","standard");
add_exit("este",MINAS+"minas_126.c","standard");
add_exit("sudeste",MINAS+"minas_147.c","standard");
}
