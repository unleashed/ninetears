// Made by Thalos  26/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. Desde aqui alcanzas ya a oir los trabajos de extraccion y ampliacion de las minas, ademas notas como poco a poco el aire se vuelve mas irrespirable debido a la gran concentracion de polvo que se produce durante estas labores. Por el suelo comienzas a ver algunos cascotes y suciedad a diferencia de las zonas anteriores.""\n\n");
add_item(({"cascotes"}),"Son cascotes desprendidos de las paredes en construcciones, que han sido arrastrados por los esclavos en su transito por las minas.\n"); 
add_clone(NPCS+"bixos_minas.c",random(5));
add_exit("norte",MINAS+"minas_5.c","standard");
add_exit("sur",MINAS+"minas_17.c","standard");
}
