//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(2);
add_exit("noroeste",ROOMPLAYA"PYFASU_13.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_18.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_25.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_107.c","standard");
}
