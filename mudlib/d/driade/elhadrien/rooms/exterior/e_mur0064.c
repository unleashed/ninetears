#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_murnorte.c";
void setup() {
prepara_room();
add_exit("noroeste", "/d/driade/elhadrien/rooms/exterior/e_mur0065","road");
add_exit("este", "/d/driade/elhadrien/rooms/exterior/e_mur0063","road");
}
