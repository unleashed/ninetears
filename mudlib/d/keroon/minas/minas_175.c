// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""De repente al girar un recodo te encuentras en un pasillo en construccion que todavia no presenta mas salida que por donde has llegado. Por el suelo ves diversos utiles de construccion, vigas de madera y diversos cascotes desprendidos en el proceso de creacion del corredor. Algunos esclavos trabajan en el mismo, aunque parece que las tareas aqui no son tan arduas como en las zonas dedicadas a la extraccion de piedras preciosas.""\n\n");
   add_item(({"vetas","vetas"}),"Ves una veta con multitud de piedras blanquecinas, al acercarte te das cuenta de que en realidad estas observando una veta de valiosos diamantes.\n"); 
add_exit("oeste",MINAS+"minas_174.c","standard");
}
