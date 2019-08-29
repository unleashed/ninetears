//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("norte",ROOMPLAYA"PYFACE_97.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_103.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_12.c","standard");
add_exit("oeste",ROOMPLAYA"PYFASU_6.c","standard");
}
