#define CREATOR "enialish"
#include "../path.h"
inherit "/d/driade/elhadrien/rooms/exterior/e_murnore.c";
void setup() {
prepara_room();
add_exit("norte", "/d/driade/elhadrien/rooms/exterior/e_mur0055","road");
add_exit("sur", "/d/driade/elhadrien/rooms/exterior/e_mur0053","road");
}
