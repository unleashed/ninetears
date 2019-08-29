//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(7);
add_exit("noreste",ROOMPLAYA"PYFANO_16.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_21.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFANO_24.c","standard");
}
