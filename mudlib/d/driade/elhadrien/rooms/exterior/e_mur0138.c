#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/exterior/e_mursur.c";
void setup() {
prepara_room();
add_exit("sudeste", "/d/driade/elhadrien/rooms/exterior/e_mur0139","road");
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0137","road");
}
