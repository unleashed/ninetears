//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("noreste",ROOMBQDB"BQDB_41.c","standard");
add_exit("sudoeste",ROOMBQDB"BQDB_60.c","standard");
add_exit("sudeste",ROOMBQDB"CBQDB_10.c","standard");
}
