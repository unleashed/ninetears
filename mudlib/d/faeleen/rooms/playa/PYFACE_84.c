//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

  habitacion(1);
add_exit("norte",ROOMPLAYA"PYFACE_75.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_85.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_93.c","standard");
}
