#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursude.c";
void setup() {
prepara_room();
add_exit("sudeste", "/d/driade/elhadrien/rooms/exterior/e_mur0015","road");
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0013","road");
}
