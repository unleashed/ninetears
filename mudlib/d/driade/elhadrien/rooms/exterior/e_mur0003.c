#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/exterior/e_mursur.c";
void setup() {
prepara_room();
add_exit("sudeste", "/d/driade/elhadrien/rooms/exterior/e_mur0004","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0001","road");
}
