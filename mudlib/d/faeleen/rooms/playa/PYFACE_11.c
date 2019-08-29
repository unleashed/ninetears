//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_10.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_12.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_20.c","standard");
add_exit("norte",ROOMPLAYA"PYFANO_50.c","standard");
}
