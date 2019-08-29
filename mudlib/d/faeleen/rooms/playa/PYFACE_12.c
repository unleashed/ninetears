//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_11.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_4.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_13.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_21.c","standard");
}
