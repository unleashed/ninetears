#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_muroeste.c";
void setup() {
prepara_room();
add_exit("sudoeste", "/d/driade/elhadrien/rooms/exterior/e_mur0104","road");
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0102","road");
}