#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/exterior/e_mursur.c";
void setup() {
prepara_room();
add_exit("este", "/d/driade/elhadrien/rooms/exterior/e_mur0140","road");
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0138","road");
}
