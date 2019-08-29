//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(2);
add_exit("noroeste",ROOMPLAYA"PYFANO_51.c","standard");
add_exit("noreste",ROOMPLAYA"PYFANO_52.c","standard");
add_exit("oeste",ROOMPLAYA"PYFACE_17.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_27.c","standard");
}
