#define CREATOR "enialish"
#include "../path.h"
inherit "/std/outside.c";
void setup() {
set_short("%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Porton del Oeste%^RESET%^");
set_long("\n%^BOLD%^Ciudad de %^CYAN%^Elhadrien%^WHITE%^:%^BLACK%^ "
"Porton del Oeste%^RESET%^\n\n"
"Esta es otra de las entradas de la ciudad. No resulta tan atractiva como "
"el acceso principal pero sin duda es de gran utilidad para los guardias que "
"patrullan el exterior de la muralla. Aunque menos importante esta tan bien "
"defendida como la entrada sur.\n\n");
add_exit("dentro", "/","door");
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0108","road");
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0110","road");
set_light(60);
}
