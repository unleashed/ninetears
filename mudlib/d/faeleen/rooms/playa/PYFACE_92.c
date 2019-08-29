//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_91.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_82.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_0.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_1.c","standard");
}
