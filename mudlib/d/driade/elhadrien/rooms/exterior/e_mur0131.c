#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursudo.c";
void setup() {
prepara_room();
add_exit("este", "/d/driade/elhadrien/rooms/exterior/e_mur0132","road");
add_exit("oeste", "/d/driade/elhadrien/rooms/exterior/e_mur0130","road");
}
