#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_muroeste.c";
void setup() {
prepara_room();
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0114","road");
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0112","road");
}
