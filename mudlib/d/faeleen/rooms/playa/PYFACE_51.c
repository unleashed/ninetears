//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(8);
add_exit("noroeste",ROOMPLAYA"PYFACE_40.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_41.c","standard");
add_exit("noreste",ROOMPLAYA"PYFACE_42.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_60.c","standard");
}
