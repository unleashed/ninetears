// Made by Thalos  26/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. A medida que te adentras en las minas, no puedes evitar fijarte en la magnifica construccion de los tuneles, se observa por doquier la mano de obra de los expertos duergars unicamente igualada por los maestros enanos. Alla donde mires la roca se encuentra pulida por el trabajo de los expertos constructores duergars, que consiguen dotar al lugar de una vida propia que te mantiene fascinado durante unos instantes, unicamente interrumpido por el paso de alguna molesta rata esporadica, y el lamento de algun esclavo.""\n\n");
add_exit("noreste",MINAS+"minas_19.c","standard");
add_exit("sudeste",MINAS+"minas_37.c","standard");
}
