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
   "cascotes por el suelo, deberias llevar cuidado de no tropezar.  Ves enormes filones "
   "de cobre en las paredes. El aire es mas denso e incluso un susurro al final de la "
   "mina puede ser  escuchado aqui, por lo que deberias llevar cuidado con tus palabras. "
   " Un enorme estruendo viene del fondo de la mina. Necesitas aire fresco y rapido!!.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cobre"}),"Son varios filones de cobre. En esta zona de la mina es donde mas abunda.\n");

add_clone(NPCSMINAS+"minero2.c",random(8)+2);
add_clone(NPCSMINAS+"guardiasminas2.c",random(3));
add_clone(NPCSMINAS+"guardianminas2.c",random(2));

//Salidas disponibles
add_exit("este","d/keroon/minas/minas2/minas2_11.c","standard");
add_exit("oeste","d/keroon/minas/minas2/minas2_09.c","standard");
}
