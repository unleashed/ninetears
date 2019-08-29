//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bl.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("oeste",ROOMBQLO"/BQLO_112.c","standard");
add_exit("noreste",ROOMBQLO"BQLO_102.c","standard");
add_exit("sudeste",ROOMBQLO"BQLO_120.c","standard");
}
