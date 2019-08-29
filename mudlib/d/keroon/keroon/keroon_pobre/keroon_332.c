// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Avenida de la separacion con Calle de la subida%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Avenida de la separacion con Calle de la subida%^RESET%^.\n\n""Estas en el cruce de la avenida de la separacion con la calle de la subida en la zona pobre de Keroon, esta avenida es conocida por el sobrenombre de la avenida de la desesperacion, debido a que sirve de separacion entre la zona pobre de la ciudad y la rica, asi como de linea de defensa interna en el caso de recibir un ataque, aunque no esta claro si este ataque seria de fuerzas externas o de los propios duergars, a tal efecto la avenida esta disenyada con zonas muy amplias a las que siguen zonas mas angostas, autenticos cuellos de botellas, que permiten que pocos duergars puedan defender amplias zonas de la avenida, causando grandes bajas a las tropas atacantes.""\n\n");

add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre.c",random(5));

add_exit("oeste",PARQUE+"keroon_331.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_311.c","standard");
//add_exit("este",KEROONPOBRE+"keroon_333.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_348.c","standard");
}
