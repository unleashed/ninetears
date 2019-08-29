// Made by Thalos  25/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("cementerio");
   set_exit_color("white");
   set_light(20);
   set_short("%^BOLD%^Cementerio abandonado%^RESET%^");
   set_long("\n%^BOLD%^Cementerio abandonado%^RESET%^.\n\n""Te encuentras en la entrada de un cementerio abandonado, delante tuyo se alzan unas majestuosas puertas de bronce con finos grabados ya borrados por el tiempo.""\n\n");

add_exit("puertas",CEMENTERIO+"cemen_84.c","standard");
add_exit("este",CAMINO+"cami_76.c","standard");
}



