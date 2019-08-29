//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(2);
add_exit("noreste",ROOMPLAYA"PYFASU_0.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_7.c","standard");
add_exit("oeste",ROOMPLAYA"PYFACE_101.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_92.c","standard");
}
