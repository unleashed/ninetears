// Made by Thalos  23/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("camkeroon");
   set_exit_color("red");
   set_light(20);
   set_short("%^CYAN%^%^BOLD%^Tuneles sombrios hacia %^BLACK%^Keroon%^RESET%^");
   set_long("\n%^CYAN%^BOLD%^Tuneles sombrios hacia %^BLACK%^Keroon%^RESET%^.\n\n""Estas en los tuneles que llevan a la bella ciudad duergar de Keroon,  fijandote mejor ves que aunque desgastados sus suelos  y paredes por los incontables pasos de las patrullas y mercaderes, estos aun conservan la belleza que le supieron imprimir los mejores maestross duergars de la piedra.""\n\n");
add_exit("oeste",CAMINO+"cami_39.c","corridor");
add_exit("noreste",CAMINO+"cami_31.c","corridor");
add_exit("este",CAMINO+"cami_41.c","corridor");
add_exit("sur",CAMINO+"cami_50.c","corridor");
}
