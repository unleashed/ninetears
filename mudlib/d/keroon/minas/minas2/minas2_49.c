// Made by valar  12/07/02

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Entras en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. Puedes ver las "
   "vetas de cobre sobresalir de las paredes y los mineros trabajando sin descanso "
   "para sacar la mayor cantidad posible. El aire comienza a ser mas irrespirable "
   "a cada paso que das. ""\n\n");
   
add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cobre"}),"El filon de cobre es mas importante aqui, ves fragmentos mas grandes por el suelo.\n");
add_item(({"antorchas"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("sur","d/keroon/minas/minas2/minas2_81.c","standard");
add_exit("este","d/keroon/minas/minas2/minas2_50.c","standard");
add_exit("oeste","d/keroon/minas/minas2/minas2_48.c","standard");
add_exit("noreste","d/keroon/minas/minas2/minas2_28.c","standard");
}
