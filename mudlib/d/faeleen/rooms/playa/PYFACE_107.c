//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("norte",ROOMPLAYA"PYFACE_104.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_108.c","standard");
add_exit("oeste",ROOMPLAYA"PYFASU_13.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_17.c","standard");
}
