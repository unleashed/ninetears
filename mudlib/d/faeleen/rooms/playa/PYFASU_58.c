//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(4);
add_exit("noreste",ROOMPLAYA"PYFASU_53.c","standard");
add_exit("este",ROOMPLAYA"PYFASU_59.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFASU_66.c","standard");
add_exit("sur",ROOMPLAYA"PYFASU_65.c","standard");
add_exit("sudoeste",ROOMPLAYA"PYFASU_64.c","standard");
}
