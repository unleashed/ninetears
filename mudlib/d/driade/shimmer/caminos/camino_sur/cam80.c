/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_zone("zhyrkh");
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Entrada de %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Entrada de %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Ante ti se abren ya las puertas de la ciudad orca de Zhyrkh, la muralla continua hacia el "
   "norte y el sur rodeando la propia ciudad, es una gran muralla de unos cinco metros de alto, de un "
   "material negro que desconoces, toda cubierta de un musgo verdoso que desprende un olor apestoso,\n\n");

add_clone(NPCS+"espaderos_orcos.c",2);

add_exit("oeste",ZHYRKH+"lalala.c","standard");
add_exit("este",CAMSUR+"cam79.c","standard");

}