/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {
   set_zone("murallahagn");
   set_exit_color("red");
   set_light(50);
   set_short("Muralla Sur del Reino de %^BOLD%^%^CYAN%^Hagn %^RESET%^");
   set_long("Muralla Sur del Reino de %^BOLD%^%^CYAN%^Hagn %^RESET%^\n\nA tu lado se erige una inmensa muralla que recorre serpenteando la llanura hasta donde "
   "te alcanza la vista siempre al lado del camino en el que te encuentras. Al acercarte a la muralla "
   "puedes contemplar el material rocoso, negro y frio, si lo miras fijamente puedes observer tu propio "
   "reflejo deformado sobre la rugosa superficie, el mundo parece distinto al verse reflejado en tan hostil "
   "material, un mundo frio y asolado, quizas como el que se encuentra tras la propia muralla.\nAl noreste "
   "puedes ver una enorme puerta en la roca de unos dos metros de alto, al mirar por ella puedes ver un "
   "descampado por el que discurre un rio de agua rojiza.\n\n");

add_clone(NPCS+"nomada.c",random(2)); 

add_exit("sudeste",HAGN+"arco_desolacion.c","standard");
add_exit("noreste",HAGN+"encrucijada_rio_rojo.c","standard");
add_exit("oeste",HAGN+"mur76.c","standard");

}