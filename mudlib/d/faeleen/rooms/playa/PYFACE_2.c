//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_1.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_0.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_3.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_6.c","standard");
}