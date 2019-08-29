// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. Escuchas un sordo sonido y sientes una rafaga de aire fresco en tu cara,de modo que al levantar la vista hacia el techo descubres uno de los numerosos pozos de ventilacion que permiten que se pueda trabajar en las minas sin riesgo de asfixiarse debido al intenso polvo que se genera, asi como las posibles bolsas de gas que puedan encontrarse durante la extracion del mineral.""\n\n");
add_clone(NPCSMINAS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_147.c","standard");
add_exit("noroeste",MINAS+"minas_126.c","standard");
add_exit("sudeste",MINAS+"minas_151.c","standard");
}
