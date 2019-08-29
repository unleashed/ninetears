/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("blue");
   set_zone("pasadizo");
   set_light(20);
   set_short("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^");
   set_long("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^\n\n"
   "Estas en una especie de pasadizo subterraneo, puedes ver un poco ya que sobre tu cabeza esta "
   "la salida del mismo, y la luz entra entre las numerosas ramas que cubren el agujero. Miras hacia "
   "el fondo y no ves mas que oscuridad, es un lugar frio y muy humedo, puedes oir levemente el correteo "
   "del agua de algun arrollo subterraneo.\n\n");

add_clone(NPCS+"varios_pasadizo_subterraneo.c",random(3));

add_exit("arriba",BOSQUEHARAK+"entrada_cueva.c","standard");
add_exit("sudoeste",SUBT+"pas2.c","standard");


}