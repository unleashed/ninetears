// Made by Thalos  26/03/02

inherit "/std/underground";
#include "vagoneta.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual discurren unos railes destinados a la circulacion de las vagonetas que trasportan los minerales y  piedras preciosas extraidos del interior de las minas. Ante ti pasa velozmente una de las distintas vagonetas cargada de minerales y conducida por un minero duergar que la transporta a las zonas de forja para su fundido y posterior utilizacion.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_exit("oeste",MINAS+"minas_14.c","standard");
add_exit("noroeste",MINAS+"minas_8.c","standard");
add_exit("sudeste",MINAS+"minas_23.c","standard");
}