//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_16.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_26.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_53.c","standard");
add_exit("norte",ROOMPLAYA"PYFANO_51.c","standard");
}
