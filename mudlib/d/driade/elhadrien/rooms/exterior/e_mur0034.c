#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mureste.c";
void setup() {
prepara_room();
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0035","road");
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0033","road");
}
