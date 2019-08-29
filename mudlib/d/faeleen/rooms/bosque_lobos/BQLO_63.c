//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bl.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("noroeste",ROOMBQLO"/BQLO_56.c","standard");
add_exit("este",ROOMBQLO"BQLO_64.c","standard");
add_exit("sudoeste",ROOMBQLO"BQLO_70.c","standard");
}
