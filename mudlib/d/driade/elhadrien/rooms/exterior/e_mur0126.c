#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mursudo.c";
void setup() {
prepara_room();
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0127","road");
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0125","road");
}
