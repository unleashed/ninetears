#define CREATOR "enialish"
#include "../path.h"
inherit "d/driade/elhadrien/rooms/interior/a_esperanza.c";
void setup() {
prepara_room();
set_exit_color("yellow");
add_exit("norte", "/d/driade/elhadrien/rooms/interior/esp0002","road");
add_exit("sur", "/d/driade/elhadrien/rooms/interior/entrada_in","road");
//set_exit_color("yellow");
}
