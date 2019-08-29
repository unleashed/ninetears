//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_102.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_98.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_104.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_13.c","standard");
}
