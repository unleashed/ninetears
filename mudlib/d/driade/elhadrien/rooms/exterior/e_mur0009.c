#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/exterior/e_mursur.c";
void setup() {
prepara_room();
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0010","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0008","road");
}
