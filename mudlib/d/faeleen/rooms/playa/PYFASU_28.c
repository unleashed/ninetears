//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(4);
add_exit("noreste",ROOMPLAYA"PYFASU_24.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_29.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_36.c","standard");
}
