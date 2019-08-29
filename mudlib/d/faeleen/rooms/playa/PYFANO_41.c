//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(2);
add_exit("noroeste",ROOMPLAYA"PYFANO_36.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFANO_46.c","standard");
add_exit("oeste",ROOMPLAYA"PYFACE_0.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_3.c","standard");
}
