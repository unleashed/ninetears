//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(5);
add_exit("oeste",ROOMPLAYA"PYFANO_49.c","standard");
add_exit("noreste",ROOMPLAYA"PYFANO_45.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_11.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_4.c","standard");
}
