/* By Shimmer */

#include "../path.h"

inherit "/std/room";

void setup() {
   set_zone("cienaga");
   set_light(50);
   set_short("Encrucijada del %^BOLD%^%^RED%^Rio Rojo%^RESET%^");
   set_long("Encrucijada del %^BOLD%^%^RED%^Rio Rojo%^RESET%^\n\nAl sur la Muralla del Reino de Hagn "
   "surca el horizonte por ambos flancos hasta perderse entre la niebla. A tu lado un rio de apenas "
   "unos metros de ancho baja cargado de un agua rojiza que despende un olor putrefacto que te cala "
   "en los huesos, este color se debe a la sangre vertida en batallas de tiempos lejanos, que como "
   "si de un maleficio se tratara continua aun fresca sobre esta esteril tierra, inundandolo todo.\n"
   "A este y oeste ves como el sendero continua aun un poco mas alla de donde te alcanza la vista, y "
   "al norte se abre ante ti una inmensa llanura pantanosa, conocida como la %^WHITE%^Cienaga%^RESET%^ de los Espectros.\n\n");


add_exit("sudeste",HAGN+"mur2.c","standard");
add_exit("sudoeste",HAGN+"mur77.c","standard");
add_exit("este",HAGN+"rio6.c","standard");
add_exit("oeste",HAGN+"rio4.c","standard");
add_exit("norte",HAGN+"cie9.c","standard");
add_exit("noroeste",HAGN+"cie8.c","standard");
add_exit("noreste",HAGN+"cie10.c","standard");
}