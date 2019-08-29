//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(5);
add_exit("norte",ROOMPLAYA"PYFANO_39.c","standard");
add_exit("noreste",ROOMPLAYA"PYFANO_40.c","standard");
add_exit("sudoeste",ROOMPLAYA"PYFANO_50.c","standard");
add_exit("sur",ROOMPLAYA"PYFACE_4.c","standard");
add_exit("este",ROOMPLAYA"PYFACE_1.c","standard");
}
