#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_murnorte.c";
void setup() {
prepara_room();
add_exit("noreste", "/d/driade/elhadrien/rooms/exterior/e_mur0081","road");
add_exit("sudoeste", "/d/driade/elhadrien/rooms/exterior/e_mur0083","road");
}
