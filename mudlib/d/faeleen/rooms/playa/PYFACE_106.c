//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_105.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_101.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_109.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_7.c","standard");
}
