//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(2);
add_exit("norte",ROOMPLAYA"PYFANO_47.c","standard");
add_exit("sudeste",ROOMPLAYA"PYFANO_53.c","standard");
add_exit("oeste",ROOMPLAYA"PYFACE_8.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_17.c","standard");
}
