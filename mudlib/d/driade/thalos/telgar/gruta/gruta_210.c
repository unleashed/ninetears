// Made by Thalos  22/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("grutas");
   set_exit_color("red");
   set_light(20);
   set_short("%^RED%^BOLD%^Grutas de Telgar%^RESET%^");
   set_long("\n%^RED%^BOLD%^Grutas de Telgar%^RESET%^.\n\n""Te encuentras en unas grutas de bajo techo, que sin duda fueron creadas por la naturaleza, aunque de vez en cuando encuentras marcas que indican la mano de una mente inteligente,  te das cuenta de que debes prestar atencion al camino recorrido si no quieres perderte""\n\n");
add_exit("oeste",GRUTA+"gruta_209.c","corridor");
add_exit("noreste",GRUTA+"gruta_196.c","corridor");
add_exit("sur",GRUTA+"gruta_227.c","corridor");
}
