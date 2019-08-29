// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Has llegado al final de unos de los distintos corredores en los cuales se extrae una gran variedad de piedras preciosas destinadas al comercio y enriquecimiento de la raza duergar, asi como para la ornamentacion de la ciudad. Dada la escasez y valor de este tipo de vetas de mineral, aqui solo trabajan los mejores mineros duergars. De vez en cuando ves algun destello en la veta debido a las gemas que hay en su interior, y observas como las tecnicas de extraccion son mucho mas precisas y delicadas.""\n\n");
add_item(({"veta"}),"Es una veta de un mineral rojizo, solo el grito de sorpresa de un minero te hace comprender que es una veta de rubies que despues seran utilizados para crear bellos objetos.\n");
add_exit("sur",MINAS+"minas_5.c","standard");
}
