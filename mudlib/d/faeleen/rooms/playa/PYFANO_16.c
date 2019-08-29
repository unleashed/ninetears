//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(7);
add_exit("noreste",ROOMPLAYA"PYFANO_11.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_17.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFANO_22.c","standard");
add_exit("sur",ROOMPLAYA"PYFANO_21.c","standard");
add_exit("sudoeste",ROOMPLAYA"PYFANO_20.c","standard");
}
