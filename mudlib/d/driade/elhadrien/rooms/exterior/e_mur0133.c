#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursudo.c";
void setup() {
prepara_room();
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0134","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0132","road");
}
