#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mureste.c";
void setup() {
prepara_room();
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0050","road");
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0048","road");
}
