//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(8);
add_exit("norte",ROOMPLAYA"PYFACE_51.c","standard");
add_exit("fuera",ROOMPLAYA"PYFACE_61.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_70.c","standard");
}
