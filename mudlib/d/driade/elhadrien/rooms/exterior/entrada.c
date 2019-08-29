#define CREATOR "enialish"
#include "../path.h"
inherit "/std/outside.c";
void setup() {
set_short("%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Puertas de la Ciudad%^RESET%^");
set_long("\n%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Puertas de la Ciudad%^RESET%^\n\n"
"Estas ante las puertas de Elhadrien, la ciudad de los Elfos de la Luz. Esta "
"ciudad ha permanecido durante siglos libre de la amenaza de las razas "
"malvadas gracias a su solida estructura y sus habiles guerreros. Dos enormes "
"portones metalicos de color plateado hechos de alguna aleacion que "
"desconoces te cierran el paso. En cada uno de ellos hay un dragon y al estar "
"cerradas las puertas se encuentran con las miradas enfrentadas. Te sientes "
"minusculo ante tal vision.\n\n");
add_exit("dentro", "/d/driade/elhadrien/rooms/interior/entrada_in","door");
add_exit("este", "/d/driade/elhadrien/rooms/exterior/e_mur0001","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0002","road");
add_exit("sur", "/d/driade/elhadrien/rooms/camino/camino0001","road");
set_light(60);
add_item("dragon","Es un dragon plateado que mira en direccion al centro "
"de la puerta. Esta en posicion defensiva, con las alas abiertas, las garras "
"en alto y en retroceso.");
add_item("dragones","Dos seres majestuosos que aparentan estar en combate "
"el uno contra el otro.");
}
