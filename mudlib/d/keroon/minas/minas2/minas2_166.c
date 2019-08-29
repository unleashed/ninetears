// Made by valar  12/07/0

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Entras en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. Hay mas filones "
   "de cristal de los que jamas hubieras podido imaginar. Es como estar en una enorme "
   "bola de cristal y asi te lo parece puesto que tus pulmones te duelen al respirar. "
   "Creo que no deberias permanecer aqui mucho tiempo.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cristales"}),"Toda la zona esta llena de piedras preciosas de todos los tipos, es un filon enorme.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("norte","d/keroon/minas/minas2/minas2_153.c","standard");
}
