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
   "cascotes por el suelo, deberias llevar cuidado de no tropezar. Atras quedaron las "
   "piedras preciosas y el cobre. Empiezan a aparecer restos de carbon y a desaparecer "
   "los de cobre. La luz apenas se refleja en estas paredes y ves la necesidad de salir "
   "al exterior y respirar  aire fresco. Las antorchas iluminan el pasillo.""\n\n");
   
add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones","carbon"}),"En esta zona de la mina encuentras que el carbon tadavia abunda.\n");
add_item(({"antorchas"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));


//Salidas disponibles
add_exit("sur","d/keroon/minas/minas2/minas2_91.c","standard");
add_exit("este","d/keroon/minas/minas2/minas2_72.c","standard");
add_exit("oeste","d/keroon/minas/minas2/minas2_70.c","standard");
}
