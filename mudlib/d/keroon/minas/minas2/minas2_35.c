// Made by valar  12/07/02

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Estas en el segundo nivel de la mina, aqui ves como abundan los mineros y los "
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. En esta seccion "
   "de la mina empiezan a aparecer filones cobre importantes. El ruido de picos y palas "
   "puede ser oido por toda la mina. El aire comienza a se hace mas y mas pesado a cada "
   "paso.""\n\n");

add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cristales"}),"Toda la zona esta llena de piedras preciosas de todos los tipos, es un filon enorme.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("noroeste","d/keroon/minas/minas2/minas2_18.c","standard");
add_exit("sudoeste","d/keroon/minas/minas2/minas2_63.c","standard");
}
