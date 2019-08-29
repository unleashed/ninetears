//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("sur",ROOMPLAYA"PYFACE_2.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_41.c","standard");
add_exit("oeste",ROOMPLAYA"PYFANO_40.c","standard");
add_exit("norte",ROOMPLAYA"PYFANO_36.c","standard");
}
