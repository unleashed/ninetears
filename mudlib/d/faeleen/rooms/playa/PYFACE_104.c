//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(0);
add_exit("oeste",ROOMPLAYA"PYFACE_103.c","standard");
add_exit("norte",ROOMPLAYA"PYFACE_99.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_105.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_107.c","standard");
}
