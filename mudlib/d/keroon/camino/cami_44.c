// Made by Thalos  23/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("camkeroon");
   set_exit_color("red");
   set_light(20);
   set_short("Tuneles sombrios hacia %^BOLD%^BLACK%^Keroon%^RESET%^");
   set_long("\nTuneles sombrios hacia %^BOLD%^BLACK%^Keroon%^RESET%^.\n\n""Estas en los tuneles que llevan a la bella ciudad duergar de Keroon,  fijandote mejor ves que aunque desgastados sus suelos  y paredes por los incontables pasos de las patrullas y mercaderes, estos aun conservan la belleza que le supieron imprimir los mejores maestros duergars de la piedra.""\n\n");
add_exit("oeste",CAMINO+"cami_43.c","corridor");
add_exit("este",CAMINO+"cami_45.c","corridor");
}
