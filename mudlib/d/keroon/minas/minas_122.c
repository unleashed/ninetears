// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "vagoneta.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual discurren unos railes destinados a la circulacion de las vagonetas que trasportan los minerales y piedras preciosas extraidos del interior de las minas. Debido al amplio transito de vagonetas que se produce, mas de una vez estas a punto de ser aplastado por una de ellas, asi que intentas en lo posible alejarte de los railes para mayor seguridad, al mismo tiempo que uno de los guardias te indica que te separes de los railes.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_clone(NPCSMINAS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_121.c","standard");
add_exit("norte",MINAS+"minas_92.c","standard");
add_exit("este",MINAS+"minas_123.c","standard");
}
