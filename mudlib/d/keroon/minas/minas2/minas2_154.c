// Made by valar  12/07/0

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Estas en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar.  Ves enormes filones "
   "de cobre en las paredes. El aire comienza a hacerser pesado y se te seca la garganta. "
   "Ves una muchedumbre de trabajadores por toda la mina trabajando sin descanso."
   " Un enorme estruendo viene del fondo de la mina. Los ojos te pican y casi no puedes "
   "articular palabra.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","carbon"}),"En esta zona de la mina encuentras que el carbon tadavia abunda.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("norte","d/keroon/minas/minas2/minas2_141.c","standard");
add_exit("sur","d/keroon/minas/minas2/minas2_167.c","standard");
}
