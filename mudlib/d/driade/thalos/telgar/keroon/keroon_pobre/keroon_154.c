// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Avenida de la separacion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Avenida de la separacion%^RESET%^.\n\n""Estas en la avenida de la separacion en la zona pobre de Keroon, esta avenida es conocida por el sobrenombre de la avenida de la desesperacion, debido a que sirve de separacion entre la zona pobre de la ciudad y la rica, asi como de linea de defensa interna en el caso de recibir un ataque, aunque no esta claro si este ataque seria de fuerzas externas o de los propios duergars, a tal efecto la avenida esta disenyada con zonas muy amplias a las que siguen zonas mas angostas, autenticos cuellos de botellas, que permiten que pocos duergars puedan defender amplias zonas de la avenida, causando grandes bajas a las tropas atacantes.""\n\n");
add_clone(NPCS+"guardian_keroon_pobre.c",random(2)); 
add_exit("norte",KEROONPOBRE+"keroon_135.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_179.c","standard");
}
