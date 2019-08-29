//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_pf.c";
#include "../path.h"

void setup() {

   habitacion(7);
add_exit("oeste",ROOMPLAYA"PYFANO_16.c","standard");
add_exit("norte",ROOMPLAYA"PYFANO_11.c","standard");
add_exit("este",ROOMPLAYA"PYFANO_18.c","standard");
add_exit("sur",ROOMPLAYA"PYFANO_22.c","standard");
add_exit("sudoeste",ROOMPLAYA"PYFANO_21.c","standard");
}
