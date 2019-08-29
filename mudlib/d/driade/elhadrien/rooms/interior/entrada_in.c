#define CREATOR "enialish"
#include "../path.h"
inherit "/std/outside.c";
void setup() {
set_short("%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Salida de la Ciudad%^RESET%^");
set_long("\n%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Salida de la Ciudad%^RESET%^\n\n"
"Esta es la salida de la ciudad, donde dos enormes puertas plateadas "
"separan la seguridad y el esplendor de la ciudad del peligroso e "
"inhospito exterior. Este lado de las puertas esta decorado con dorados "
"ribetes y runas en antiguo elfico y tras sus puertas te sientes como "
"en casa.\n\n");
add_item("runas","No sabes lo que pone en ellas.");
add_exit("fuera", "/d/driade/elhadrien/rooms/exterior/entrada","door");
add_exit("este", "/d/driade/elhadrien/rooms/interior/i_mur0001","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/interior/i_mur0002","road");
add_exit("norte", "/d/driade/elhadrien/rooms/interior/elh0001","road");
set_light(60);
}
