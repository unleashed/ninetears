#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_muroeste.c";
void setup() {
prepara_room();
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0099","road");
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0097","road");
}
