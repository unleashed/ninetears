#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursudo.c";
void setup() {
prepara_room();
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0128","road");
add_exit("este", "/d/driade/elhadrien/rooms/exterior/e_mur0130","road");
}
