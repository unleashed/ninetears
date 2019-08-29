// Made by valar  12/07/0

inherit "/std/suboscuridad";
#include "/d/keroon/path.h"

void setup() {

   set_zone("minas2");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2");
   set_long("\n%^BOLD%^BLACK%^Minas de Keeroon: %^RESET%^Nivel 2.\n\n"
   " Estass en el segundo nivel de la mina. Aqui los no hay casi mineros puesto que "
   "te encuentras en una zona de la mina ya abandonada por la escasez de recursos "
   "en ella existentes. Puedes ver restos de lo que fue una importante veta de oro."
   "El aire esta lleno de polvo y polucion y se te hace casi imposible respirar aqui."
   " Deberias abandonar esta zona si no quieres morir de asfixia.""\n\n");
   
add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_item(({"filon","filones"}),"Esta seccion de la mina esta agotada por lo que no encuentras nada de interes.\n");

add_clone(NPCSMINAS+"bixos_minas2.c",random(4));

//Salidas disponibles
add_exit("norte","d/keroon/minas/minas2/minas2_136.c","standard");
add_exit("sur","d/keroon/minas/minas2/minas2_162.c","standard");
}
