//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_15.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_8.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_17.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_25.c","standard");
}
