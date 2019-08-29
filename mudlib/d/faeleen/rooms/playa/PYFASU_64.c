//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(4);
add_exit("noreste",ROOMPLAYA"PYFASU_58.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_65.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFASU_73.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_72.c","standard");
}
