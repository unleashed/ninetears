#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursude.c";
void setup() {
prepara_room();
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0020","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0018","road");
}
