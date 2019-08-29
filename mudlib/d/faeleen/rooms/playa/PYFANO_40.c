//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(2);
add_exit("noreste",ROOMPLAYA"PYFANO_36.c","standard");
add_exit("sudoeste",ROOMPLAYA"PYFANO_45.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_1.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_0.c","standard");
}
