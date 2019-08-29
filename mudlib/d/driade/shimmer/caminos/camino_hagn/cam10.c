/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {
   set_zone("caminohagn");
   set_exit_color("white");
   set_light(50);
   set_short("%^BOLD%^WHITE%^Cruce del camino hacia %^BOLD%^%^CYAN%^Hagn%^RESET%^");
   set_long("%^BOLD%^WHITE%^Cruce del camino hacia %^BOLD%^%^CYAN%^Hagn%^RESET%^\n "
   "Estas en un cruce, miras a tu alrededor y ves tres posibles rutas que tomar, al norte "
   "ves una gran muralla que se extiende por todo el horizonte, al sur puedes ver una gran "
   "cumbre neveda y al este el camino gira sobre una colina y se pierde en el valle.\n\n"
   "Cartel.\n\n");
    
    add_item("cartel","Estas en el cruce del camino hacia Hagn:\n\n "
    "   Norte: Reino de Hagn\n    Sudoeste: Harak-Din\n    Este: Patatin patatan\n\n");

add_clone("/d/driade/shimmer/hahn/npcs/nomada.c",1);

add_exit("norte",CAMHAGN+"cam9.c","standard");
add_exit("sudoeste",CAMHAGN+"cam11.c","standard");
add_exit("este",CAMHAGN+".c","standard");

}