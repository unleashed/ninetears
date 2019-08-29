//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(2);
add_exit("noroeste",ROOMPLAYA"PYFANO_41.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_47.c","standard");
add_exit("oeste",ROOMPLAYA"PYFACE_3.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_8.c","standard");
}
