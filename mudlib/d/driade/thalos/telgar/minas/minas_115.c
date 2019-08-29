// Made by Thalos  26/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. Lllegado a este punto el tunel se bifurca en varias galerias por las cuales los diversos esclavos y mineros se van repartiendo hacia sus zonas de trabajo. En la paredes puedes ver diversas flechas con indicaciones que se�alan la direccion hacia donde se encuentra la salida de la minas y a que puntos se dirigen las diversas galerias.""\n\n");
add_clone(NPCS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_114.c","standard");
add_exit("noroeste",MINAS+"minas_90.c","standard");
add_exit("este",MINAS+"minas_116.c","standard");
add_exit("sur",MINAS+"minas_145.c","standard");
}
