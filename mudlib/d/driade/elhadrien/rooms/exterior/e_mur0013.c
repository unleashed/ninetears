#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/exterior/e_mursur.c";
void setup() {
prepara_room();
add_exit("sudeste", "/d/driade/elhadrien/rooms/exterior/e_mur0014","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0012","road");
}
