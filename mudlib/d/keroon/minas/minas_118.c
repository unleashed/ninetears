// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Has llegado al final de unos de los distintos corredores en los cuales se extrae una gran variedad de minerales destinados a la forja de armas y armaduras, asi como carbon para alimentar dichas forjas. Puedes observar a varios esclavos encadenados, picando arduamente una veta de mineral bajo la atenta mirada de un guardian. De forma mas distendida ves como varios mineros duergars trabajan tambien sobre la meta de mineral a la espera de que alguna incursion al exterior traiga nuevos esclavos.""\n\n");
add_item(({"veta","vetas"}),"Ves una rica veta de carbon que esta siendo extraido y cargado en vagonetas, para que alimente el fuego de las forjas.\n"); 
add_exit("oeste",MINAS+"minas_117.c","standard");
}
