#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_mureste.c";
void setup() {
prepara_room();
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0046","road");
add_exit("sudeste", "/d/driade/elhadrien/rooms/exterior/e_mur0044","road");
}
