// Made by Valar  12/07/02

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Entras en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. El aire es irrespirable, notas como a tus "
   "pulmones te duelen al respirar. No deberias permanecer aqui mucho tiempo.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cobre"}),"Son varios filones de cobre. En esta zona de la mina es donde mas abunda.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles

add_exit("sudeste","d/keroon/minas/minas2/minas2_16.c","standard");
}
