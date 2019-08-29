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
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. En esta zona "
   "aprecias como los carros ya no van cargados de cobre, sino de Piedras Preciosas"
   "%^RESET%^y carbon. "
   "Los obreros se encuentran mas fatigados por la escasez de oxigeno de esta zona. "
   "EL aire se encuentra corrupto e irrespirable. �Seguiras caminando?""\n\n");
   
add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","cristales"}),"Toda la zona esta llena de piedras preciosas de todos los tipos, es un filon enorme.\n");
add_item(({"antorchas"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("este","d/keroon/minas/minas2/minas2_64.c","standard");
add_exit("oeste","d/keroon/minas/minas2/minas2_62.c","standard");
add_exit("noreste","d/keroon/minas/minas2/minas2_35.c","standard");
}
