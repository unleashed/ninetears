//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_100.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_91.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_106.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_1.c","standard");
}
